#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>




class player
{
protected:
    int money;
    std::string name;
    int position;
    int roundcnt;

public:

    const std::string& getname()
    {
        return name;
    }

    int getmoney()
    {
        return money;
    }


    virtual bool shouldpay(int price) = 0;

    player (const std::string& paramname)
    {
        name = paramname;
        money = 10000;
        position = 0;
        roundcnt = 0;
    }

    int getroundcnt()
    {
        return roundcnt;
    }

    bool isalive()
    {
        return money > 0;
    }

    int getposition()
    {
        return position;
    }

    void movetoposition(int newposition)
    {
        position = newposition;
        roundcnt++;
    }

    void pay(int price)
    {
        money -= price;
    }

};


class field
{


public:



    virtual void buy (player* playername)
    {
        playername->pay(price(playername));
    }

    virtual int price(player* playername) const = 0;
};





class greedy : public player
{
public:

    greedy(const std::string& playername) : player(playername)
    {

    }

    bool shouldpay(int price)
    {
        return true;
    }
};

class careful : public player
{
public:

    careful(const std::string& playername) : player(playername)
    {

    }

    bool shouldpay(int price)
    {
        return this->money / 2 > price;
    }

};

class tactical : public player
{
public:

    tactical(const std::string& playername) : player(playername)
    {

    }

    bool shouldpay(int price)
    {
        return roundcnt % 2 == 0;
    }

};



class service : public field
{

public:

    service (int param)
    {
        paramprice = param;
    }


    void buy(player* playername)
    {
        playername->pay(this->price(playername));
    }

    int paramprice;

    int price (player* playername) const
    {
        return paramprice;
    }
};

class lucky : public field
{
public:
    lucky (int param)
    {
        paramprice = param;
    }

    int paramprice;



    int price (player* playername) const
    {
        return -paramprice;
    }
};

class ingatlan : public field
{

private:
    player* owner;
    bool istherehouse;
    bool hasOwner = false;

public:

    void clear()
    {
        owner = nullptr;
        istherehouse = false;
        hasOwner = false;
    }

    void buy(player* playername)
    {
        int currentprice = price(playername);
        if(!owner)
        {
            owner = playername;
            playername->pay(currentprice);
        }
        else if(playername != owner)
        {
            playername->pay(currentprice);
            owner->pay(-currentprice);
        }
        else if(!istherehouse)
        {
            istherehouse = true;
            owner->pay(currentprice);
        }

        hasOwner = true;

    }


    ingatlan()
    {
        clear();
    }

    player* getowner() const
    {
        return owner;
    }

    int price (player* playername) const
    {

        //return 0;
        if (hasOwner)
        {
            if (owner == playername)
            {
                return 4000;
            }
            else if (!istherehouse)
            {
                return 500;
            }
            else
            {
                return 2000;
            }

        }
        else
        {
            return 1000;
        }


    }
};

class track
{
private:
    std::vector<field*> fields;
    std::vector<player*> players;

public:

    void results()
    {
        std::ofstream data ("../plot/data.dat");

        for (int i = 0; i < players.size(); ++i)
        {

            data << players[i]->getname() << ' ' <<   players[i]->getmoney();
            if (dynamic_cast<greedy*>(players[i]))
            {
                data << " greedy" << ' ';
            }
            if (dynamic_cast<tactical*>(players[i]))
            {
                data << " tactical" << ' ';
            }
            if (dynamic_cast<careful*>(players[i]))
            {
                data << " careful" << ' ';
            }
            for (int j = 0; j  < fields.size(); ++j)
            {
                ingatlan* property =dynamic_cast <ingatlan*>(fields[j]);
                if (property && property->getowner() == players[i])
                {
                    data << ' ' << j;
                }

            }
            data << std::endl;
        }
        data.close();
    }

    void addfield(const std::string& fieldtype, int ar)
    {
        if (fieldtype == "ingatlan")
        {
            ingatlan* ing = new ingatlan();
            ing->clear();
            fields.push_back(ing);
        }

        else if (fieldtype == "service")
        {
            fields.push_back(new service(ar));
        }

        else if(fieldtype == "lucky")
        {
            fields.push_back(new lucky(ar));
        }
        else
            std::cout << "wrong fieldtype" << fieldtype << std::endl;
    }

    void addplayer ( const std::string& playertype, const std::string& playername)
    {
        if (playertype == "greedy")
        {
            players.push_back(new greedy(playername));
        }

        if (playertype == "tactical")
        {
            players.push_back(new tactical(playername));
        }

        if (playertype == "careful")
        {
            players.push_back(new careful(playername));
        }
    }

    void play(int roundc)
    {
        for (int round = 0; round < roundc; ++round)
        {
            for (int nrplayer = 0; nrplayer < players.size(); ++ nrplayer)
            {

                int dice = rand() % 6 + 1;
                //std::cout << "rounds " << dice << std::endl;
                player* currentplayer = players[nrplayer];
                if(!currentplayer->isalive())
                {
                    continue;
                }
                int position = newposition(currentplayer, dice);
                currentplayer->movetoposition(position);
                field* currentfield = fields[position];

                int price = currentfield->price(currentplayer);
                //std::cout << price << std::endl;
                if (currentplayer->shouldpay(price))
                {
                    currentfield->buy(currentplayer);
                }

                if(!currentplayer->isalive())
                {
                    for (int i = 0; i < fields.size(); ++i)
                    {
                        ingatlan* current = dynamic_cast <ingatlan*>(fields[i]);
                        if(current  && current->getowner() == currentplayer)
                        {
                            current->clear();
                        }
                    }
                }

            }
        }
    }


    int newposition(player *p, int dice)
    {
        return (p->getposition() + dice) % fields.size();
    }

};

int main()
{
    srand(time(0));

    std::ifstream f("../teszt.txt");
    if(!f)
    {
        std::cout << "Nem nyert" << std::endl;
    }
    track palya;
    int rounds;
    f >> rounds;

    int nrfields;
    f >> nrfields;

    for (int i = 0; i < nrfields; ++i)
    {
        std::string fieldname;
        f >> fieldname;
        int ar;
        if (fieldname != "ingatlan")
        {
            f >> ar;
        }
        palya.addfield(fieldname, ar);
    }

    int nrplayer;
    f >> nrplayer;

    for (int i = 0; i < nrplayer; ++i)
    {
        std::string playername;
        std::string playertype;

        f >> playername;
        f >> playertype;

        palya.addplayer(playertype, playername);
    }

    palya.play(rounds);
    palya.results();
    
    f.close();



    return 0;
}

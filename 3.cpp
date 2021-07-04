#include<iostream>
#include<fstream>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<map>
using namespace std;
void ffind(int,int,int,vector <vector<int>>);
short atoii(string);
void ap(vector < map<short,int>>,vector<short>,int,vector<short>);
vector<vector<int>>re;
vector<string>finn;
int ma=0;
int answer=0;
int main()

{
    float start=clock();
    vector <string>orig ;
    map<short,int>tem ;
    vector < map<short,int>> peo;
    vector<short>can;
    int te;

    te=0;
    string line;
    fstream fin;
    string testr;
    fin.open("T15I7N0.5KD1000K.txt",ios::in);
    while(getline(fin,line))
    {
        line+=",";
        orig.push_back(line);

        // cout<<"line = "<<line<<endl;

    }
    //cout<<"orig.size() = "<<orig.size()<<endl;

    /*for(int i=0;i<orig.size();i++)
    {

            //cout<<orig.at(i)<<endl;
        }*/
    cout<<'\n';
    for(int i=0; i<orig.size(); i++)
    {
        for(int j=0; j<orig.at(i).size(); j++)
        {





            if(orig.at(i)[j]<='9'&&orig.at(i)[j]>='0')//&&orig.at(i)[j]1=' ')
            {

                testr+=orig.at(i)[j];
            }
            else
            {
                // cout<<"testr = ["<<testr<<"]"<<endl;
                //cout<<"else"<<endl;


                if(testr.length()!=0)
                {
                    tem.insert(pair<short,int>(atoii(testr),1));
                    testr="";
                }
            }





        }



        peo.push_back(tem);
        tem.clear();


    }
    /*for(int j=0; j<peo.size(); j++)
    {
        for(auto k=peo.at(j).begin();k!=peo.at(j).end();k++)
        {
            cout<<k->first<<" ";
        }
        cout<<endl;
    }*/




        for(short i=0; i<500; i++)
        {
            int n=0;
            for(int j=0; j<peo.size(); j++)
            {
                auto k=peo.at(j).find(i);
                if(k!=peo.at(j).end())
                {
                    n++;
                }

            }

            if(n<30000)
            {
                for(int j=0; j<peo.size(); j++)
                {

                    peo.at(j).erase(i) ;
                }

            }
            else
            {
                can.push_back(i);
                //answer++;
            }
            n=0;
        }
        cout<<answer<<endl;



        vector<short>now;
        now.clear();


        ap(peo,can,0,now);
        /*for(int i=0;i<re.size();i++)
        {
            for(int j=0;j<re.at(i).size();j++)
            {
                cout<<re.at(i).at(j)<<" ";
            }
            cout<<endl;
        }*/
        float endd=clock();
        cout<<answer<<endl;
        cout<<(endd-start)/1000;





        return 0;
    }


    short atoii(string str)
    {

        int te=0;
        int j=str.length();
        for(int k=1; str.length()>=k; k++)
        {
            //cout<<(int)(orig.at(i)[j-k]);
            //cout<<(int)(orig.at(i)[j-k])-48<<endl;


            te=((short)(str[j-k])-48)*pow(10,k-1)+te;
            // cout<<te<<endl;

        }

        return te;
    }
    void ap( vector < map<short,int>>peo,vector<short>cand,int ind,vector<short>now)
    {
        int nind=ind;


        for(int i=ind; i<cand.size(); i++)
        {
            int n=0;

            vector < map<short,int>>npeo;




            for(int j=0; j<peo.size(); j++)
            {

                auto k=peo.at(j).find(cand.at(i));
                if(k!=peo.at(j).end())
                {
                    n++;
                    npeo.push_back(peo.at(j));
                }
            }
            if(n>=30000)
            {
                now.push_back(cand.at(i));
                answer++;
                //cout<<"si="<<now.size()<<endl;
                /*for(int p=0;p<now.size();p++)
                {cout<<now.at(p)<<" ";}
                cout<<endl;*/



                ap(npeo,cand,i+1,now);
                now.pop_back();
            }
            /*else
            {
                if(now.size()>ma)
                {
                    ma=now.size();
                    re.clear();
                    re.push_back(now);

                }
                if(now.size()==ma&&re.at(re.size()-1)!=now)
                {
                    re.push_back(now);

                }
            }*/
            n=0;


        }

    }

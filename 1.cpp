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
void ap(vector < map<short,int>>*,map<short,int>*,vector<short>);
vector<vector<int>>re;
vector<string>finn;
int ma=0;
int answer=0;
float start=clock();
float aptime=0;
int main()

{
    ios_base::sync_with_stdio(false);

    vector <string>orig ;
    map<short,int>tem ;
    vector < map<short,int>> peo;
    map<short,int>can;
    int te;

    te=0;
    string line;
    fstream fin;
    string testr;
    fin.open("T15I7N0.5KD10K.txt",ios::in);//T15I7N0.5KD1K
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
                map<short,int>::iterator k=peo.at(j).find(i);
                if(k!=peo.at(j).end())
                {
                    n++;
                }

            }

            if(n<50)
            {
                for(int j=0; j<peo.size(); j++)
                {

                    peo.at(j).erase(i) ;
                }

            }
            else
            {
                can.insert(pair<short,int>(i,1));
                //answer++;
            }
            n=0;
        }




        vector<short>now;
        now.clear();


        ap(&peo,&can,now);
        /*for(int i=0;i<re.size();i++)
        {
            for(int j=0;j<re.at(i).size();j++)
            {
                cout<<re.at(i).at(j)<<" ";
            }
            cout<<endl;
        }*/
        float endd=clock();
        cout<<answer<<'\n';
        cout<<(endd-start)/1000;


    printf("ap_time = %f\n",aptime);


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
    void ap( vector < map<short,int>>*peo,map<short,int>*cand,vector<short>now)
    {

        float t=clock();

        for(map<short,int>::iterator i=(*cand).begin(); i!=(*cand).end(); i++)
        {
            int n=0;

            vector < map<short,int>>npeo;
            map<short,int>ncand;




            for(int j=0; j<(*peo).size(); j++)
            {

                 map<short,int>::iterator k=(*peo).at(j).find(i->first);
                if(k!=(*peo).at(j).end())
                {
                    n++;
                    // while((*peo).at(j).begin()->first!=i->first)
                   {
                       (*peo).at(j).erase((*peo).at(j).begin());
                   }



                    //cout<<"rr"<<peo.at(j).begin()->first<<endl;
                   for(map<short,int>::iterator l=(*peo).at(j).begin();l!=(*peo).at(j).end();l++)
                    {ncand.insert(pair<short,int>(l->first,1));}

                    npeo.push_back((*peo).at(j));
                }
            }
            
            if(n>=50)
            {
            for(int j=0; j<(*peo).size(); j++)
                {

                 map<short,int>::iterator k=(*peo).at(j).find(i->first);
                if(k!=(*peo).at(j).end())
                    {
                   
                    //cout<<"rr"<<peo.at(j).begin()->first<<endl;
                   for(map<short,int>::iterator l=(*peo).at(j).begin();l!=(*peo).at(j).end();l++)
                    {ncand.insert(pair<short,int>(l->first,1));}

                    npeo.push_back((*peo).at(j));
                        }
                }
                now.push_back(i->first);
                answer++;

                //for(int p=0;p<now.size();p++)
                //{cout<<now.at(p)<<" ";}
               // cout<<endl;




                ap(&npeo,&ncand,now);
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
        //aptime += (clock()-m  )/1000;


    }

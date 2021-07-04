#include<iostream>
#include<fstream>
#include<vector>
#include<math.h>
#include<stdlib.h>
using namespace std;
void ffind(int,int,int,vector <vector<int>>);
int atoii(string);
vector<string>finn;
int main()
{

vector <string>orig ;
vector <int>tem ;
vector <vector<int>> peo;

int te,n,a1,b1,c1,a2,b2,c2;
n=0;
te=0;
string line;
fstream fin;
string testr;
    fin.open("T15I7N0.5KD1K.txt",ios::in);
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
    for(int i=0;i<orig.size();i++)
    {
        for(int j=0;j<orig.at(i).size();j++)
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
                    tem.push_back(atoii(testr));
                    testr="";
                }
            }





        }



        peo.push_back(tem);
        tem.clear();


    }

    for(int i=0;i<peo.size();i++)
    {
        for(int j=0;j<peo.at(i).size();j++)
        {
           // cout<<peo.at(i).at(j);
            //cout<<" ";
        }
        //cout<<endl;


    }

    for(int i=0;i<1000;i++)
    {
        for(int j=0;j<peo.size();j++)
        {
            for(int k=0;k<peo.at(j).size();k++)
            {
                if (peo.at(j).at(k)==i)
                {
                    n++;
                }
            }
        }
        if(n<5)
        {
            for(int j=0;j<peo.size();j++)
            {
                for(int k=0;k<peo.at(j).size();k++)
                {
                    if (peo.at(j).at(k)==i)
                    {
                        peo.at(j).erase(peo.at(j).begin()+k);
                    }

                }
            }

        }
        n=0;
    }

    /*for(int i=0;i<peo.size();i++)
    {
        for(int j=0;j<peo.at(i).size();j++)
        {
            cout<<peo.at(i).at(j);
        }
        cout<<endl;
    }*/

    for(int i=0;i<peo.size();i++)
    {
        if(peo.at(i).size()<3)
        {
            peo.erase(peo.begin()+i);
            i--;
        }
    }
    /*cout<<"qqqqqqqqqqqqqqqqqqqqq"<<endl;
    for(int i=0;i<peo.size();i++)
    {
        for(int j=0;j<peo.at(i).size();j++)
        {
            cout<<peo.at(i).at(j);
        }
        cout<<endl;
    }*/
    for(int i=0;i<peo.size();i++)
    {
        for(int j=0;j+2<peo.at(i).size();j++)
        {
            for(int k=j+1;k+1<peo.at(i).size();k++)
            {
                for(int l=k+1;l<peo.at(i).size();l++)
                {
                    a1=peo.at(i).at(j);
                    b1=peo.at(i).at(k);
                    c1=peo.at(i).at(l);
                    ffind(a1,b1,c1,peo);
                    for(int r=0;r<finn.size()-1;r++)
                    {
                        if(finn.at(r)==finn.at(finn.size()-1))
                        {
                            finn.erase(finn.end());
                        }
                    }

                }
            }
        }
    }
    for(int r=0;r<finn.size();r++)
                    {
                       cout<<finn.at(r)<<endl;
                    }








return 0;}
void ffind(int a1,int b1,int c1,vector <vector<int>> peo)
{
    int a2,b2,c2;
    string tem;
    a2=b2=c2=0;
     for(int i=0;i<peo.size();i++)
     {
         for(int j=0;j<peo.at(i).size();j++)
         {
             if(a1==peo.at(i).at(j))
             {
                 a2++;
             }
             if(b1==peo.at(i).at(j))
             {
                 b2++;
             }
             if(c1==peo.at(i).at(j))
             {
                 c2++;
             }
         }

     }
     if(a2>4&&b2>4&&c2>4)
     {
         //cout<<a1<<b1<<c1<<endl;

         tem={(char)(a1+48),(char)(b1+48),(char)(c1+48)};
         finn.push_back(tem);
     }

}
int atoii(string str)
{

    int te=0;
    int j=str.length();
                     for(int k=1;str.length()>=k;k++)
                {
                    //cout<<(int)(orig.at(i)[j-k]);
                   //cout<<(int)(orig.at(i)[j-k])-48<<endl;


                    te=((int)(str[j-k])-48)*pow(10,k-1)+te;
                   // cout<<te<<endl;

                }

                return te;
}

#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;
struct SS
{
    vector <int> vec;
};
int main() {
    for (int test = 1; test <= 5; test++) {
        ifstream in(to_string(test) + ".txt");
        SS *arr;
        int n,k ,d=1,b=0,c=0;
        in >> n;
        arr = new SS[n];
        vector<int> g(n);
        for (int i = 0; i < n; i++) {
            in >> g[i];
            for (int j = 0; j < g[i]; j++) {
                in>>k;
                (arr+i)->vec.push_back(k);
             
            }
        }
        
            
        
        for(int i = 0; i < n; i++){
            
            for(int j = 0; j < g[i]; j++)
            {
                for(int k=1+j;k<g[i];k++)
                {
                    if((arr+i)->vec[j]==(arr+i)->vec[k]){c++;}
                    if(c>2){break;}
                }
                if(d==(arr+d-1)->vec[j]){b++;}
                if( b==2){break;}
            }
            if(c>2){break;}
            if(b==2){break;}
            b=0;
            
    }
       
        if(c<1){cout<<test<<" Граф:Yes"<<"\n";}
        else{cout<<test<<" Граф:No"<<"\n";}
    }
    return 0;

}

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void calculate(vector<int> cowsInfarm, int M, int farms, int C){
    for(int j=0; j<M; j++){
        int size = cowsInfarm.size();
        for(int i=0; i<size; i++){
            if(cowsInfarm.at(i)*2 > C){
                cowsInfarm.push_back( cowsInfarm.at(i) );
                farms++;
            }
            else
            {
                cowsInfarm.at(i) = cowsInfarm.at(i)*2;            
            }           
        }  
    }
    cout<<endl<<"farms : "<<farms<<endl;
}

int main(){
    vector<int> cowsInfarm, RegulatorArrival;
    int C,N,M;
    cin>>C>>N>>M;
    int farms = N, number_of_farm_at_day_zero = N ;
    
    for(int i=0; i<N; i++){
       int temp;
       cin>>temp;
       cowsInfarm.push_back(temp);
    }
    
    for(int i=0; i<M; i++){
       int temp;
       cin>>temp;
       RegulatorArrival.push_back(temp);
    }

    for(int i=0; i<RegulatorArrival.size(); i++){
        calculate(cowsInfarm, RegulatorArrival.at(i), farms, C);
    }

    return 0;    
}
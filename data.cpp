#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<stdexcept>
#include<string>
#include"data.h"
using namespace std;
Data::Data(ifstream&f):X(),Y(){
    string line;
    while (getline(f,line)){
        istringstream s(line);
        double temp;
        matrix sample;
        string label;
        sample.col=1;
        sample.row=0;
        while(s>>temp){
            sample.m.push_back(temp);
            sample.row+=1;
        }
        s>>label;
        X.push_back(sample);
        Y.push_back(label);
    }
}

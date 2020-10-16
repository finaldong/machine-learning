#include<fstream>
#include<sstream>
#include<vector>
#include<stdexcept>
#include<string>
#include"Data.h"
using namespace std;
Data::Data(ifstream&file):X(),Y(){
    const int featureNums=4;//需要修改成合适的
    string line;
    while (getline(file,line)){
        istringstream LineStream(line);
        double temp;
        matrix sample;//默认每个样本是行向量
        sample.col=1;
        sample.row=0;
        while(sample.row<=featureNums&&(LineStream>>temp)){
            sample.m.push_back(temp);
            sample.row+=1;
        }
        string label;
        LineStream>>label;
        X.push_back(sample);
        Y.push_back(label);
    }
}

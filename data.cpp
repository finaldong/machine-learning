#include<fstream>
#include<sstream>
#include<vector>
#include<stdexcept>
#include<string>
#include"Data.h"
using namespace std;
Data::Data(ifstream&file):X(),Y(){
    const int featureNums=4;//��Ҫ�޸ĳɺ��ʵ�
    string line;
    while (getline(file,line)){
        istringstream LineStream(line);
        double temp;
        matrix sample;//Ĭ��ÿ��������������
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

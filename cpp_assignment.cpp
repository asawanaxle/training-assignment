#include<bits/stdc++.h>
#include<iostream>
 #include<unistd.h>
 #include <getopt.h>

using namespace std;

class Application{
    public:
    vector<vector<string>> vectorMatrix;

    string truncateWhiteSpaces(string str)
    {
        str.erase(remove(str.begin(), str.end(), ' '), str.end());
        return str;
    }

    void pushWord(string s[]){
        int k=0;
        for (int i = 0; i < 1; i++)
        {
            vector<string> v;
            for (int j = 0; j < 9; j++) {
                s[k] = truncateWhiteSpaces(s[k]);
                v.push_back(s[k++]);
            }
            vectorMatrix.push_back(v);
        }
    }

    void readFile(){
        string myText;

        ifstream MyReadFile("sample_input.in");
        string tempArray[45];
        while(getline (MyReadFile, myText)){
            cout << myText<<endl;
            string temp;
            string tempArray[9];
            int k=0;
            temp = myText.substr(0,15);
            tempArray[k++] = temp;

            temp = myText.substr(14,15);
            tempArray[k++] = temp;

            temp = myText.substr(29,15);
            tempArray[k++] = temp;

            temp = myText.substr(44,10);
            tempArray[k++] = temp;

            temp = myText.substr(54,5);
            tempArray[k++] = temp;

            temp = myText.substr(59,20);
            tempArray[k++] = temp;

            temp = myText.substr(79,15);
            tempArray[k++] = temp;

            temp = myText.substr(94,15);
            tempArray[k++] = temp;

            temp = myText.substr(109,7);
            tempArray[k++] = temp;

            pushWord(tempArray);
            
        }
        for (int i = 0; i < vectorMatrix.size(); i++)
            {
                for (int j = 0; j < vectorMatrix[i].size(); j++)
                {
                    cout << vectorMatrix[i][j] ;
                }    
                cout << endl;
            }
    }

    void envelopeFormat(){
        fstream fstream_ob;
        fstream_ob.open("envelopeOutput.txt", ios::app);
        for(int i=0;i<5;i++){
            fstream_ob << vectorMatrix[i][0] << " ";
            fstream_ob << vectorMatrix[i][1] << endl;
            fstream_ob << vectorMatrix[i][4] << " ";
            fstream_ob << vectorMatrix[i][5] << endl;
            fstream_ob << vectorMatrix[i][6] << "," << " " << vectorMatrix[i][7] << " " << vectorMatrix[i][8]<<"\n\n";
        }
        fstream_ob.close();
    }

    void fixedFormat(){
        fstream fstream_ob;
        fstream_ob.open("fixedOutput.txt", ios::app);
        for(int i=0;i<5;i++){
            fstream_ob << vectorMatrix[i][1] << " " << vectorMatrix[i][0] << "\t\t" <<  vectorMatrix[i][4] << " " << vectorMatrix[i][5] << "\t\t" << vectorMatrix[i][6] << ", " << vectorMatrix[i][7] << " " << vectorMatrix[i][8] << "\n\n";
        }
        fstream_ob.close();
    }

    void csvFormat(){
        fstream fstream_ob;
        fstream_ob.open("csvOutput.txt", ios::app);
        for(int i=0;i<5;i++){
            fstream_ob << "\"" << vectorMatrix[i][1] << " " << vectorMatrix[i][0] << "\"" << "," << "\"" << vectorMatrix[i][4] << " " << vectorMatrix[i][5] << "\"" << "," <<  "\"" << vectorMatrix[i][6] << "," << " " << vectorMatrix[i][7] << " "  << vectorMatrix[i][8] << "\"" << "\n\n";
        }
        fstream_ob.close();
    }
};
int main(int argc, char *argv[]){
    
    
    Application a;
    a.readFile();
    a.envelopeFormat();
    a.fixedFormat();
    a.csvFormat();
}
    

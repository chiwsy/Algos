#include<iostream>
#include<fstream>
#include<set>
using namespace std;

int main(){
    int N;
    ifstream fin("in.txt");
    ofstream fout("out.txt");
    fin>>N;

    for(int times=0;times<N;times++){
        fout<<"Case #"<<times+1<<": ";
        set<int> firstr;
        set<int> secondr;
        int row;
        fin>>row;
        int tmp;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                fin>>tmp;
                if(i==row-1) firstr.insert(tmp);
            }
        }
        fin>>row;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                fin>>tmp;
                if(i==row-1) secondr.insert(tmp);
            }
        }
        tmp=0;
        for(set<int>::iterator sit=firstr.begin();sit!=firstr.end();++sit){
            if(secondr.find(*sit)!=secondr.end()){
                tmp++;
                row=*sit;
            }
        }
        if(tmp==0) fout<<"Volunteer cheated!\n";
        else if(tmp==1) fout<<row<<endl;
        else fout<<"Bad magician!\n";
    }
return 0;
}

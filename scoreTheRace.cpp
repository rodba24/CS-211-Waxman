#include<iostream>
using namespace std;
int main(){
    string result;
    cout << "Enter a race: ";
    cin >> result; 
    int teams[26]={0};
    double scores[26]={0};
    int flag=0;
    
    for(int i=0; i<result.length(); i++ ){
        if (((int)result[i]>=65 && (int) result[i]<=90)) {
            teams[(int)result[i]-65]+=1; 
            scores[(int)result[i] - 65] += (i + 1);
        } else {
            cout << "error no lower case letter" << endl;
            break;
        }
      }
        int firstTeam = -1;
    for (int i = 0; i < 26; i++) {
        if (teams[i] > 0) {
            firstTeam = i;
            break;
        }
    }
    if (firstTeam == -1) {
        cout << "There are no teams" << endl;
        return 0;
    }
    
    for (int i = 0; i < 26; i++) {
        if (teams[i] > 0 && teams[i] != teams[firstTeam]) {
            flag = 1;
            break;
        }
    }
    
    if (flag !=0) {
        cout << "Not all teams have equal value" << endl;
      exit(0);
    }


  int numberOfTeams=0;
    for(int i=0; i< 26; i++)
        if(teams[i]>0) numberOfTeams++; 
    cout<<"There are "<< numberOfTeams << " teams"<<endl;

for (int i = 0; i < 26; i++) {
    if (teams[i] > 0) {
        cout << "Team " << (char)(i + 65) <<" has " << teams[i]<< " runners" << endl<<endl;
    }
}
  cout << "TEAMS            SCORES"<<endl;
  double avg=0;
  for (int i = 0; i < 26; i++) {
if (teams[i] > 0) {
  avg = scores[i] / teams[i];          
  cout<< (char)(i + 65) <<"                  "           <<avg<<endl;
 
  }
    }
  char winningTeam;
  double winningScore= 100000000000;
  for (int i = 0; i < 26; i++) {
if (teams[i] > 0) {
  avg = scores[i] / teams[i];
  if(avg<winningScore) {
    winningScore= avg;
    winningTeam= (char)(i+65);
  }
  }
    }
  cout<<"The winning team is "<< winningTeam<< " with a score of "<< winningScore<<endl; 
    
    return 0;
}

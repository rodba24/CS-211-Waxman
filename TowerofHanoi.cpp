#include <iostream>
#include <vector>
using namespace std;


int main(){
    vector<int> t[3];
    // three towers A,B,C represented as an array of 3 vectors
    int n, candidate,to, from, move=0; // move counts the move number
    cout<<"Please enter a number of rings to move: ";
    cin>>n;
    cout<<endl;

    //intitialize the 3 towers
    for(int i=n+1;i>=1;i--)
        t[0].push_back(i);
    t[1].push_back(n+1);
    t[2].push_back(n+1);

    // initialize towers and candidate
    from=0;
    if((n%2)==1) to=1; // if #of rings is odd to is 1
    else to=2;
    candidate=1;
  
    while( t[1].size()<n+1){ // while the second tower does not yet contain all disks in the correct order

        // move top disk from current "from" tower to current "to" tower
      
        t[to].push_back(t[from].back());//place ring in "to"
        t[from].pop_back();//take out ring from "from"
      // print message indicating that a disk has been moved
        cout<<"move number "<<++move<<": Transfer ring "<<candidate<<" from tower "<<char(from+65)<<" to tower "<<char(to+65)<<endl;
        

// determine next "from" tower, "to" tower, and candidate disk
      
        if(n%2==1){  //if there are an odd number of rings

          //from tower
            if(t[(to+1)%3].back() < t[(to+2)%3].back())
                from=(to+1)%3;
            else
                from=(to+2)%3;
          
            // get next“to tower”
          
            if(t[(from)].back() < t[(from+1)%3].back())
                to=(from+1)%3;
            else
                to=(from+2)%3;
            //get next candidate
            candidate=(t[from].back()); // it’s on the top of the current “from tower”
          
        } 
        else {                    // if there are an even number of rings
            if(t[(to+1)%3].back() < t[(to+2)%3].back())
                from=(to+1)%3;
            else
                from=(to+2)%3;
            // get next“to tower”
            if(t[(from)].back() < t[(from+2)%3].back())
                to=(from+2)%3;
            else
                to=(from+1)%3;
            //get next candidate
            candidate=(t[from].back()); // it’s on the top of the current “from tower”
        }
    }
    return 0;
}
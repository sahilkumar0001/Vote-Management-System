/*-----------------------------------------------------------------------------------------------------------------
                                      VOTE MANAGEMENT SYSTEM USING C++
-----------------------------------------------------------------------------------------------------------------*/

#include<iostream>

using namespace std;
string usr;
int pass , choice , voted , leading;
int count =0;
int vote;
string Candidates[5]={"Dr.Amrinder Singh", "Adityanath Yogi", "Akhilesh Yadav", " Arvind Kejriwal", "Smt.Mayawati" };//Array of candidates

int votes[5]={0,0,0,0,0};                                             //number of votes initially

string voter[20]={"Sahil", "Saurabh","Amar", "Aman","Pawan","Rahul","Atter", "Krishna","Adarsh","Dharu","Nayan","Vivek","Mukesh","Suri","Vishal", "Anuj", "Anupam","Ashneer", "Sameer", "Parveen"};           //Voter ID's

int password[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};//Voter's password

int valid[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

int Welcome();
void Cand_Show();
void CandwVotes();
int CandwMax();
int selOption();
int selOptionIfvoted();
void castVote();

int main(){

 //Label invoked when user selects logout or enters wwrong credentials 
Jump:                                                              
    count = Welcome();    
    if(count==1){

//Label invoked when user selects wrong option 
Option:                                                         
            
            
     //Checking if the candidate has already voted or not!                                                           
    choice = (valid[voted]==0)?selOption():selOptionIfvoted();      
    if(choice==0){
        system("CLS");
        cout<<"Exited!";
        exit(0);
    }   
    while(choice!=0){
        if(choice==1) {
            Cand_Show();
            castVote();
             //Checking if the candidate has already voted or not!
            choice = (valid[voted]==0)?selOption():selOptionIfvoted();     
        }
        else if(choice==2) {
            CandwVotes();
             //Checking if the candidate has already voted or not!
            choice = (valid[voted]==0)?selOption():selOptionIfvoted();
        }
        else if(choice==3) {
            leading=CandwMax();
            if(leading>=0){
            cout<<"\n\nLeading Candidate";
            cout<<"\n________________________\n\n";
            cout<<Candidates[leading] <<" "<<votes[leading]<<"\n________________________\n";
            }
            
             //Checking if the candidate has already voted or not!
            choice = (valid[voted]==0)?selOption():selOptionIfvoted();

        }
        else if(choice==4) {
          goto Jump;
        }
        else {
            cout<<"Enter a valid Option.";
            
            goto Option;
        }
    }   
} 
else{
            cout<<"Wrong Credentials!!"<<endl;
            cout<<"Enter Correct Credentials: "<<endl;
            
            goto Jump;
        } 
    return 0;
}

//Input Username and password
int Welcome(){                                                        
    cout<<"\nEnter your voter ID: ";
    cin>>usr;
    cout<<"Enter your Password: ";
    cin>>pass;
    for(int i=0; i<20; i++){//password match
        
       if(usr == voter[i] && pass==password[i]){  
            voted=i;  
            if(valid[i]==1){
            cout<<"\nYou cannot vote again-----:(\n";
            }        
            return 1;
            
        }       
    }
}

//input menu
int selOption(){                                                      
    int choice;
        cout<<"\nSelect any one Option: "<<endl<<endl;
         cout<<"\n 1.Vote for your favourite candidate \n 2.Check the number of votes of each candidate \n 3.Check the candidate who is leading  \n 4.Log Out\n 0.Exit"<<endl;
         cout<<"Choice: ";
         cin>>choice;
         cout<<endl;
         return choice;
}

//input menu if voted
int selOptionIfvoted(){                                               
    int choice;
        cout<<"\nSelect any one Option: "<<endl<<endl;
         cout<<" 1.You have already voted.-pressing 1 will Exit\n 2.Check the number of votes of each candidate \n 3.Check the candidate who is leading \n 4.Log Out\n 0.Exit "<<endl;
         cout<<"Choice: ";
         cin>>choice;
         if(choice==1){
            Welcome();
         }
         return choice;
}

//Voting a candidate
void castVote(){                                                      
    cout<<"Choose the Candidate you want to Vote: ";
    cin>>vote;
    if(vote>5 || vote<1){
        cout<<"\nSelect valid candidate"<<endl;
    }
    else{
        votes[vote-1]+=1;
        cout<<"\nVoted Successfully!"<<endl;
        valid[voted]=1;
    } 
}

//list of candidates
void Cand_Show(){                                                     
    cout<<"List of Candidates:"<<endl<<endl;
    for (int i=0; i<5; i++){
        cout<<i+1<<" "<<Candidates[i]<<endl;
    }
}

//list of candidates with their votes
void CandwVotes(){                                                    
    cout<<"List of Candidates with number of votes:"<<endl<<endl;
    for(int i=0; i<5;i++){
        cout<<i+1<<" "<<Candidates[i]<<" "<<votes[i]<<endl;
    }
}

//Leading candidate           
int CandwMax(){                                                      
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
        if(i==j){
            continue;
        }
        else if(votes[i]>votes[j]){
            return i;
        }
        // else if(votes[i]==votes[j] || votes[i]==votes[j] || votes[i]==votes[j] || votes[i]==votes[j] || votes[i]==votes[j]){

        // }
        
        
     }
    }
}

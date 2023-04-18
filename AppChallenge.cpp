#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<locale.h>

using namespace std;


class FileReader {
public:
        
    vector<string> nameVector;
    vector<string> vacantVector;
    vector<int> ageVector;
    vector<string> stateVector;

    void read() {

        ifstream file("AppAcademy_Candidates.csv");

        string index;
    
        getline(file, index, '\n');

        for (int i = 0; file.good(); i++) {
            
            string name;
            string vacant;
            string age;
            string state;
            
            
            getline(file, name, ';');
            getline(file, vacant, ';');
            getline(file, age, ';');
            getline(file, state, '\n');

            string replacedstring = age.replace(2, 6, "");

            int x = stoi(replacedstring);
            
            nameVector.push_back(name);
            vacantVector.push_back(vacant);
            ageVector.push_back(x);
            stateVector.push_back(state);

        }

        file.close();
    }

    void percentageOfCandidates() {
        
        int apiNetCount = 0;
        int iosCount = 0;
        int qaCount = 0;
        
        float percentCandidates;

        for (int i = 0; i < vacantVector.size(); i++) {

            if (vacantVector[i] == "API .NET") {
                apiNetCount++;
            }
            else if (vacantVector[i] == "iOS") {
                iosCount++;
            }
            else {
                qaCount++;
            }
        }
        cout << "porcentagem de candidatos por vaga: " << endl;
        cout << "API .NET: " << apiNetCount * 100.0/ vacantVector.size() << "%" << endl;
        cout << "iOS     : " << iosCount * 100.0 / vacantVector.size() << "%" << endl;
        cout << "QA      : " << qaCount * 100.0 / vacantVector.size() << "%"  << endl;
        
    }

    void averageAgeQA() {

        int qaCandaditeAge = 0;
        int qaCount = 0;
        
        for (int i = 0; i < ageVector.size(); i++){

             if (vacantVector[i] == "QA"){

               qaCandaditeAge += ageVector[i];
               qaCount++;
             }
        }   
            cout << endl;
            cout << "A média de idade dos candidatos de QA é: ";
            cout << qaCandaditeAge / qaCount << " Anos" << endl;
    }


    void iosOlderCandidate() {
                          
            int olderCandidateAge = 0;
            string olderCandidateName;
            
            for (int i = 0; i < ageVector.size(); i++){

                if (vacantVector[i] == "iOS"){

                    if (olderCandidateAge < ageVector[i]){

                        olderCandidateAge = ageVector[i];
                        olderCandidateName = nameVector[i];
                    }
            
                }
            }
            cout << endl;
            cout << "candidato mais velho entre os candidatos de iOS: ";
            cout << olderCandidateName << "  Idade: " << olderCandidateAge << " Anos" << endl;
    }

    void apiNetYoungerCandidate() {
           
        string nameYoungestCandidateApiNet;
        int    apiNetCandidateAge = 100;

        for (int i = 0; i < ageVector.size(); i++){

            if (vacantVector[i] == "API .NET"){

                if (apiNetCandidateAge > ageVector[i]){

                    apiNetCandidateAge = ageVector[i];
                    nameYoungestCandidateApiNet = nameVector[i];
                }

            }
        }
        cout << endl;
        cout << "Candidato mais novo entre todos os candidatos API.NET: ";
        cout << nameYoungestCandidateApiNet << "  Idade: " << apiNetCandidateAge << " Anos" << endl;
 
    }

    void sumApiNetAge() {

        int sumCandidadeApiNetAge = 0;

        for (int i = 0; i < ageVector.size(); i++){

            if (vacantVector[i] == "API .NET"){

                sumCandidadeApiNetAge += ageVector[i];
            }
        }
        cout << endl;
        cout << "soma da idade de todos os candidatos do API .NET: ";
        cout << sumCandidadeApiNetAge << " Anos" << endl;
        
    }

    void sortState() {
       
        int countState = 0;
        sort(stateVector.begin(), stateVector.end());
        
        for (int i = 0; i < stateVector.size() - 1; i++){

            if (stateVector[i] == stateVector[i+1]){
                countState++;                                            
                               
            }
                    
        }
        int differentStates = stateVector.size() - countState;
        cout << endl;
        cout << "Número de estados distintos presentes na lista: ";
        cout << differentStates << endl;
                       
    }

    void sortName() {

        sort(nameVector.begin(), nameVector.end());
             
        std::ofstream myfile;
        myfile.open("Sorted_AppAcademy_Candidates.csv");

        for (int i = 0; i < nameVector.size(); i++){

            myfile << nameVector[i] << "\n";
        }

        myfile.close();
        cout << endl;
        cout << "Lista de nomes ordenada em ordem alfabética e salva como Sorted_AppAcademy_Candidates.csv" << endl;

    }
    
     void discoveryInstructor() {
        

        string limiter = " ";
        string firstName;
        int vowelsCount = 0;

        for (int i = 0; i < nameVector.size(); i++){
                        
            firstName = nameVector[i].substr(0, nameVector[i].find(limiter));
            
            for (int i = 0; i < firstName.length(); i++){

                if (firstName[i] == 'a' || firstName[i] == 'e' || firstName[i] == 'i' ||
                    firstName[i] == 'o' || firstName[i] == 'u' || firstName[i] == 'A' ||
                    firstName[i] == 'E' || firstName[i] == 'I' || firstName[i] == 'O' ||
                    firstName[i] == 'U'){

                    vowelsCount++;

                }
                   
            }
      
           if (vowelsCount == 3){
                
                if (nameVector[i].back() == 'k'){

                    cout << endl;
                    cout << "O nome do Instrutor de API.NET é: ";
                    cout << nameVector[i] << endl;
                    
                }
           }
            
            vowelsCount = 0;
                       
        }
        
     }


        
    
};

int main() {
    setlocale(LC_ALL, "pt-br");
    FileReader fr = FileReader();
    fr.read();
    
    
    fr.percentageOfCandidates();
    fr.averageAgeQA();
    fr.iosOlderCandidate();
    fr.apiNetYoungerCandidate();
    fr.sumApiNetAge();
    fr.sortState();
    fr.sortName();
    fr.discoveryInstructor();
   
    
  
    return 0;
}

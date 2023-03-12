#include <iostream>
#include <fstream>

int last_floor(){
    std::ifstream myfile;
    std::string text = "c:\\Users\\marco\\Desktop\\advent-of-code\\2015\\1\\path.txt";
    myfile.open(text);

    if (myfile.fail()) {
        std::cerr << "Error Opening File" << std::endl;
        exit(1);
    }

    char x;
    int floor = 0;

    while(myfile >> x){
        if(x == '(')
            floor++;
        else
            floor--;
    }

    return floor;
}

int basement(){
    std::ifstream myfile;
    std::string text = "c:\\Users\\marco\\Desktop\\advent-of-code\\2015\\1\\puzzle.txt";
    myfile.open(text);

    if (myfile.fail()) {
        std::cerr << "Error Opening File" << std::endl;
        exit(1);
    }

    char x;
    int idx = 0, floor = 0;
    bool basement = false;

    while(myfile >> x && !basement){
        if(x == '(')
            floor++;
        else
            floor--;
        
        if(floor == -1){
            basement = true;
        }
        
        idx++;
    }

    return idx;
}

int main(){
    
    std::cout<<last_floor()<<std::endl;
    std::cout<<basement()<<std::endl;
    
    return 0;
}
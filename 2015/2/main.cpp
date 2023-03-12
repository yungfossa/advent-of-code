#include <iostream>
#include <fstream>

int smallest(int l1, int l2, int l3){
    return std::min(std::min(l1,l2), l3);
}

int paper_order(){
    std::ifstream myfile;
    std::string text = "c:\\Users\\marco\\Desktop\\advent-of-code\\2015\\2\\puzzle.txt";
    myfile.open(text);

    if (myfile.fail()) {
        std::cerr << "Error Opening File" << std::endl;
        exit(1);
    }

    int l, w, h, needed_paper {0};

    while(myfile >> l >> w >> h)
        needed_paper += 2*(l*w + w*h + h*l) + smallest(l*w, w*h, h*l);
        
    return needed_paper;
}

int ribbon_order(){
    std::ifstream myfile;
    std::string text = "c:\\Users\\marco\\Desktop\\advent-of-code\\2015\\2\\info.txt";
    myfile.open(text);

    if (myfile.fail()) {
        std::cerr << "Error Opening File" << std::endl;
        exit(1);
    }

    int l, w, h, needed_ribbon {0};

    while(myfile >> l >> w >> h){
        needed_ribbon += 2*smallest(h+w, l+h, l+w) + l*w*h;
    }
    
    return needed_ribbon ;
}

int main(){

    std::cout<<paper_order()<<std::endl;
    std::cout<<ribbon_order()<<std::endl;

    return 0;
}
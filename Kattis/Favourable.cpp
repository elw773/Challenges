#include <iostream>
#include <map>
#include <vector>
using namespace std;
//https://open.kattis.com/problems/favourable
struct page{
    int end;
    vector<page*> references;
    vector<page*> pages;
};

map<int, page> book;

vector<int> favourable;

void newReference(int a, int b){
    page aPage, bPage;
        auto itr = book.find(a);
        
        if(itr == book.end()){
            aPage = page();
            book.insert(pair<int, page>(a, aPage));
        } else {
            aPage = itr->second;
        }
        
    if(b>0){
        itr = book.find(b);
        if(itr == book.end()){
            bPage = page();
            book.insert(pair<int, page>(b, bPage));
        } else {
            bPage = itr->second;
        }

        aPage.pages.push_back(&bPage);
        bPage.references.push_back(&aPage);
    } else if(b==-1){
        aPage.end = -1;
        favourable.push_back(a);
    } else if(b==-2){
        aPage.end = -2;
    }

    if(a==1){
        aPage.end = -3;
    }
}

int main(){
    int cases;
    cin>>cases;
    while(cases--){
        int nPages;
        cin>>nPages;
        while(nPages--){
            int pageNumber;
            cin>>pageNumber;

            string str;
            cin>>str;
            if(str == "favourably"){
                newReference(pageNumber, -1);
            } else if(str == "catastrophically"){
                newReference(pageNumber, -2);
            } else {
                int bPageN;
                bPageN = stoi(str);
                newReference(pageNumber, bPageN);

                cin>>bPageN;
                newReference(pageNumber, bPageN);
                cin>>bPageN;
                newReference(pageNumber, bPageN);
            }
        }

        int ans;
        page curr;
        for(int end:favourable){
            curr = book.find(end);
            while(curr->second.end != -3){

            }
        }
    }


    return 0;
}
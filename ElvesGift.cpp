#include <iostream>
#include <vector>
#include <iterator>
#include <list>
#include <numeric>
#include <fstream>
#include <functional>

using namespace std;

bool compareSum(list<int> l1, list<int> l2)
{
    return std::accumulate(std::begin(l1), std::end(l1), 0) < std::accumulate(std::begin(l2), std::end(l2), 0);
}

int main()
{
    vector<list<int> > vecListGift;
    std::fstream newfile;
    newfile.open("input.txt",ios::in); 
    if (newfile.is_open()){   
      string star;
      list<int> starList;
      while(getline(newfile, star)){ 
        if (star.empty()){
            vecListGift.push_back(starList);
            starList.clear();
         }else{
            starList.push_back(stoi(star));
         }
      }
      newfile.close();
      std::sort(vecListGift.begin(), vecListGift.end(), compareSum);
      int largestGift = std::accumulate(std::begin(*(vecListGift.end() - 1)), std::end(*(vecListGift.end() - 1)), 0);
  
      cout << largestGift << endl; 
   }

    return 0;
}
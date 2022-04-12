//INCOMPLETE SOLUTION
// REVISIT AND ATTEMPT NON RECURSION or RECURSION WITH SEEN MATRIX
//
//
//
//
#include <vector>
#include <utility>
#include <iostream>
#include <string>

using namespace std;
void printImage(vector<vector<int>> input){
  string ret = "";
  for(auto ii : input){
    for(auto jj : ii){
      cout << jj;
    }
    cout <<endl;
  }
};
class Solution {
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor){
      vector<pair<int, int>> dir = {{1, 0}, {0,1}, {-1,0}, {0,-1}};
      int iiSr, iiSc;

      
      for(int ii = 0; ii < 4; ii++){
        iiSr = sr + dir[ii].first;
        iiSc = sc + dir[ii].second;
        cout << "Looping for sr = " << iiSr << " sc = " << iiSc << endl;
        if(iiSr < image.size() && iiSr >= 0){
          if(iiSc < image[iiSr].size() && iiSc >= 0){
            if(image[iiSr][iiSc] == image[sr][sc]){
              image[sr][sc] = newColor;
              cout << "Recursively calling for sr = " << iiSr << " sc = " << iiSc << endl; 
              image = floodFill(image, iiSr, iiSc, newColor);
                            image[sr][sc] = newColor;

              image[iiSr][iiSc] = newColor;
            }
          }
        }
      }
                    image[sr][sc] = newColor;

      return image;
    }


    /*    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
      vector<pair<int, int>> directions = {{1, 0}, {0,1}, {-1,0}, {0,-1}};
      for(int ii = 0; ii < 4; ii++){
        cout << "Starting Iteration: " << ii << endl << sr+directions[ii].first;
        if(sr+directions[ii].first < image.size() && sc+directions[ii].second < image[0].size()){
          cout << 1 << endl;
          if(sr+directions[ii].first >= 0 && sc+directions[ii].second >= 0){
            cout << 2 << endl;
            if(image[sr+directions[ii].first][sc+directions[ii].second] == image[sr][sc]){
              cout << 3 << endl;
              image = floodFill(image, sr+directions[ii].first, sc+directions[ii].second, newColor);
            }
          }
        }
      }
    printImage(image);
    image[sr][sc] = newColor;
    printImage(image);
      cout << "\n\n\n\n\n";
      return image;
    }*/

};


main(){
  Solution test = Solution();
  vector<vector<int>> input = {{1,1,1}, {1,1,0}, {1,0,1}};
  printImage(input);
  input = test.floodFill(input, 1, 1, 2);
  printImage(input);
  
}
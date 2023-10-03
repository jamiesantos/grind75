#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
      int scol = image[sr][sc];
      floodFillInstance(image, sr, sc, color, scol);
      cout << image.size() << " " << image[0].size() << endl;
      return image;
    }
    
    void floodFillInstance(vector<vector<int>>& image, int sr, int sc, int color, int scol) {
	  // Add check that instance matches original color, or else it'll enter an infinite loop
      if (!checkBounds(sr, sc, image) || image[sr][sc] == color || image[sr][sc] != scol) return;
      image[sr][sc] = color;
      floodFillInstance(image, sr-1, sc, color, scol);
      floodFillInstance(image, sr+1, sc, color, scol);
      floodFillInstance(image, sr, sc-1, color, scol);
      floodFillInstance(image, sr, sc+1, color, scol);
    }

    void printImage(vector<vector<int>>&image) {
      for (int i = 0; i < image.size(); ++i) {
        for (int j = 0; j < image[i].size(); ++j) {
          cout << image[i][j] << " ";
        }
        cout << endl;
       }
    }

    bool checkBounds(int sr, int sc, vector<vector<int>>& image) {
      bool check = (sr < 0 || sc < 0 || sr == image.size() || sc == image[0].size()) ? false: true;
      return check;
	}    
};

int main() {
  Solution sol;
  vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,2}};
  sol.printImage(image);
  int sr = 1;
  int sc = 1;
  int color = 2;
  vector<vector<int>> solution = sol.floodFill(image, sr, sc, color);
  sol.printImage(solution);
  return 0;
}

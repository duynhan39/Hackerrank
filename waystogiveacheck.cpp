#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

typedef struct{
    int x;
    int y;
    
    void point_t(int px, int py) {
        x=px;
        y=py;
    }
    void point_t() {}
}point_t;

int checkAsRook(vector<string> grid, point_t K, point_t P);
int checkAsBishop(vector<string> grid, point_t K, point_t P);
int checkAsQueen(vector<string> grid, point_t K, point_t P);
int checkAsKnight(vector<string> grid, point_t K, point_t P);
int check(vector<string> grid, point_t K, point_t P);
bool movable(vector<string> grid, point_t wK, point_t P, vector<point_t> black);


int main() {
    int t;
    cin>>t;
    
    for(int each=0; each<t; each++){
        point_t wK, bK, P;
        vector<point_t> black(0);
        vector<point_t> white(0);
        //vector<int> pieX(0), pieY(0);
        vector<string> grid(8);
        for(int y=0; y<8; y++) {
            for(int x=0; x<8; x++) {
                cin>>grid[y][x];
                if(grid[y][x]=='k') {
                    bK.point_t(x, y);
                } else if(grid[y][x]=='K') {
                    wK.point_t(x, y);
                } else if(isupper(grid[y][x]) && grid[y][x]!='P') {
                    point_t piece;
                    piece.point_t(x, y);
                    white.push_back(piece);
                    
                } else if(islower(grid[y][x]) && grid[y][x]!= 'p') {
                    point_t piece;
                    piece.point_t(x, y);
                    black.push_back(piece);
                    
                }
            }
        }
        
        for(int x=0; x<8; x++) {
            point_t piece;
            piece.point_t(x, 1);
            if(grid[1][x]=='P' && grid[0][x]=='#' && movable(grid, wK, piece, black)) {
                P=piece;
                P.y=0;
                grid[0][x]='P';
                grid[1][x]='#';
                break;
            }
        }
        int ways=0;
        for(auto piece:white) {
            ways=check(grid, bK, piece);
            if(ways!=0)
                break;
        }

        if(ways==0) {
            ways = checkAsBishop(grid, bK, P)
                    + checkAsRook(grid, bK, P)
                    + checkAsQueen(grid, bK, P)
                    + checkAsKnight(grid, bK, P);
        }
        cout<<ways<<endl;
    }
    return 0;
}

int checkAsRook(vector<string> grid, point_t K, point_t P) {
    bool Pass=true;
    if(K.y==P.y) {
        for(int i=min(K.x, P.x)+1; i<max(K.x, P.x); i++) {
            if(grid[P.y][i]!='#') {
                Pass=false;
                break;
            }
        }
        if(Pass)
            return 1;
    }
    Pass=true;
    if(K.x==P.x) {
        for(int i=min(K.y, P.y)+1; i<max(K.y, P.y); i++) {
            if(grid[i][P.x]!='#') {
                Pass=false;
                break;
            }
        }
        if(Pass)
            return 1;
    }
    return 0;
}

int checkAsBishop(vector<string> grid, point_t K, point_t P) {
    bool Pass=true;
    if(K.x-P.x==K.y-P.y) {
        for(int i=1; i<abs(K.y-P.y); i++) {
            if(grid[min(K.y, P.y)+i][min(K.x, P.x)+i]!='#') {
                Pass=false;
                break;
            }
        }
        if(Pass)
            return 1;
    }
    Pass=true;
    if(P.x-K.x==K.y-P.y) {
        for(int i=1; i<abs(K.y-P.y); i++) {
            if(grid[min(K.y, P.y)+i][max(K.x, P.x)-i]!='#') {
                Pass=false;
                break;
            }
        }
        if(Pass)
            return 1;
    }
    return 0;
}

int checkAsQueen(vector<string> grid, point_t K, point_t P) {
    return (checkAsRook(grid, K, P) + checkAsBishop(grid, K, P) + 1)/2;
}

int checkAsKnight(vector<string> grid, point_t K, point_t P) {
    if(abs(K.x-P.x)+abs(K.y-P.y)==3 && K.x!=P.x && K.y!=P.y)
        return 1;
    return 0;
}

int check(vector<string> grid, point_t K, point_t P) {
    int checkMate=0;
    char name = toupper(grid[P.y][P.x]);
    if(name =='R')
        checkMate = 4*checkAsRook(grid, K, P);
    else if(name =='B')
        checkMate = 4*checkAsBishop(grid, K, P);
    else if(name =='Q')
        checkMate = 4*checkAsQueen(grid, K, P);
    else if(name =='N')
        checkMate = 4*checkAsKnight(grid, K, P);
    return checkMate;
}

bool movable(vector<string> grid, point_t wK, point_t P, vector<point_t> black) {
    grid[P.y][P.x] = '#';
    grid[0][P.x] = 'P';
    for(auto piece:black) {
        if(check(grid, wK, piece))
            return false;
    }
    return true;
}


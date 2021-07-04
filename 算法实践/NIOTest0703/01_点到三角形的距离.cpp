#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
    // P到直线AB的距离
    // 求出y=kx+b, 则kx-y+b=0
    float pointToLine(vector<float>& P, vector<float>& A, vector<float>& B) { 
        float x = P[0], y = P[1];
        float x1 = A[0], y1 = A[1];
        float x2 = B[0], y2 = B[1];
        if (x1 == x2) {
            return abs(x - x1);
        }
        float k = (y2 - y1) / (x2 - x1);
        float b = y1 - k * x1;
        float d = abs(k * x - y + b) / sqrt(k * k + 1);
        return d;
    }

    // 点在三角形内？
    // PA×PB, PB×PC，PC×PA三者同号（同方向） 即是在三角形内（顺时针给出A、B、C顶点）
    // PA=(a,b) PB=(c,d) PA×PB=(a*d-c*b)k向量 根据正负判断方向
    bool inTriangle(vector<float>& P, vector<vector<float>>& triangle) { 
        vector<float> PA = { triangle[0][0] - P[0],triangle[0][1] - P[1] };
        vector<float> PB = { triangle[1][0] - P[0],triangle[1][1] - P[1] };
        vector<float> PC = { triangle[2][0] - P[0],triangle[2][1] - P[1] };
        float a = PA[0] * PB[1] - PA[1] * PB[0];
        float b = PB[0] * PC[1] - PB[1] * PC[0];
        float c = PC[0] * PA[1] - PC[1] * PA[0];

        // 因为PA PB PC 相交于P点 不会出现等于0（平行）的情况
        return a > 0 && b > 0 && c > 0 || a < 0 && b < 0 && c < 0; 
    }
public:
    float pointToTriangle(vector<float>& point, vector<vector<float>>& triangle) {
        if (inTriangle(point, triangle)) {
            return 0.0;
        }
        float d1 = pointToLine(point, triangle[0], triangle[1]);
        float d2 = pointToLine(point, triangle[0], triangle[2]);
        float d3 = pointToLine(point, triangle[1], triangle[2]);
        return min(d1, min(d2, d3));
    }
};

int main()
{
    Solution slt;
    vector<vector<float>> triangle{ {-1,-1},{0,1},{1,-1} };
    vector<float> point{ 0,0 };
    cout << slt.pointToTriangle(point, triangle) << endl;

    point = { 0,-2 };
    cout << slt.pointToTriangle(point, triangle) << endl;

    return 0;
}

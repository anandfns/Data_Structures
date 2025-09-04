class Solution {
public:
    int findClosest(int x, int y, int z) {
        if(abs(z-x) == abs(z-y)) {
            return 0;
        } else if(abs(z-x) < abs(z-y)) {
            return 1;
        } else if (abs(z-x) > abs(z-y)) {
            return 2;
        }

        return -1;
    }
};

// there are also many one liner solution exist for this like :
class Solution {
public:
    int findClosest(int x, int y, int z) {
        return abs(x-z)==abs(y-z)?0:abs(x-z)<abs(y-z)?1:2;
    }
};
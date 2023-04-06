class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        
        long long finalCount = 0;

        long long penPrice = 0;

        while(penPrice <= total){

            long long remaining = total - penPrice;
            long long pencilPrice = 0;
            long long pencilCount = remaining/cost2;

            finalCount += (pencilCount + 1);
            penPrice += cost1;
        }

        return finalCount;
    }
};

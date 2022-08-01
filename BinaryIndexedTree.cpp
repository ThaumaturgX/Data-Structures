template <typename T>
class BIT{
public:
    BIT(int size){
        bitree.assign(size+1,0);
        bitree[0] = 0;
    }
    
    BIT(std::vector<T> v): BIT(v.size()){
        for(int i = 0; i < v.size(); i++)
            add(i, v[i]);
    }
    
    void add(int pos, T val){
        ++pos;
        while(pos <= bitree.size()){
            bitree[pos] += val;
            pos += pos&-pos;
        }
    }
    
    T prefixSum(int pos){
        ++pos;
        int ans = 0;
        while(pos > 0){
            ans += bitree[pos];
            pos -= pos&-pos;
        }
        return ans;
    }
    
    T sum(int left, int right){
        return prefixSum(right) - prefixSum(left-1);
    }
    
private:
    std::vector<T> bitree;
};
class SeatManager {
public:
    set<int> res, unres;
    SeatManager(int n) {
        for(int i = 1; i <= n; i++){
            unres.insert(i);
        }
    }
    
    int reserve() {
        auto it = unres.begin();
        int seat = *it;
        unres.erase(seat);
        res.insert(seat);
        return seat;
    }
    
    void unreserve(int seatNumber) {
        res.erase(seatNumber);
        unres.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
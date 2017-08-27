class AllOne {
private:
    struct Bucket{int val; unordered_set<string> keys;};
    list<Bucket> buckets;
    unordered_map<string,list<Bucket>::iterator> table;
public:
    /** Initialize your data structure here. */
    AllOne() {
        table.clear();
        buckets.clear();

    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        auto it = table.find(key);


        ///如果不存在,则先按0插入
        if(it==table.end()){
            ///如果在table中没有找到则在对应的节点中插入一个元素
            ///返回元素的迭代器
            table[key] = buckets.insert(buckets.begin(),{0,{key}});
        }
        auto next = table[key],bucket = next++;
        ///如果插入的元素在next桶中,更新
        if(next==buckets.end()||next->val>bucket->val+1){
            next= buckets.insert(next,{bucket->val+1,{}});
        }
        next->keys.insert(key);
        table[key] = next;

        ///从旧的桶中移除key
        bucket->keys.erase(key);

        if(bucket->keys.empty()){
            buckets.erase(bucket);
        }



    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        auto it = table.find(key);

        ///如果不存在,则返回
        if(it==table.end()){
            return;
        }

        ///如果插入的元素在之前的桶中,则插入到pre桶中,否则,新增一个桶
        auto pre = it->second, bucket = pre--;

        ///更新table表,不会造成迭代器失效
        table.erase(key);

        if(bucket->val>1){
            ///如果当前的桶值,大于1,则证明要将key进行移动

            ///如果当前桶处于桶链表的开头位置,或者前一个桶比当前桶少多于1,则要新开辟一个桶
            if(bucket==buckets.begin()||pre->val<bucket->val-1){

                ///返回要插入桶的迭代器
                pre = buckets.insert(bucket,{bucket->val-1,{}});
            }

            pre->keys.insert(key);
            table[key] = pre;
        }

        ///从旧的桶中删除原来的元素

        bucket->keys.erase(key);

        if(bucket->keys.empty()){
            buckets.erase(bucket);
        }


    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        ///注意要使用rbegin 而不是 end ,end 指向最后一个元素的后一个节点
        return buckets.empty()?"": *buckets.rbegin()->keys.begin();
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return buckets.empty()?"": *buckets.begin()->keys.begin();

    }
};
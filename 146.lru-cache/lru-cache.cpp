class LRUCache {

private:
    struct Node{
        int val;
        int key;
        Node(int _val,int _key):val(_val),key(_key),next(nullptr),front(nullptr){}
        Node* next;
        Node* front;
    };

    Node *tail,*head;

    unordered_map<int,Node*> hashmap;
    int cap;
    int size;

private:
    ///把一个节点放在链表头部
    void pushFront(Node* node){
        ///往头部添加一个节点
        if(head == nullptr||hashmap.size()==0){
            head = node;
            tail = head;
            return;
        }
        if(node==head){
            ///该缓存位置为头节点
            return;
        }
        if(node==tail){
            ///该缓存位置为尾节点，则修改tail的位置
            tail = tail->front;
        }

        if(node->front!= nullptr){
            node->front->next = node->next;
        }
        if(node->next!= nullptr){
            node->next->front = node->front;
        }
        node->next = head;
        head->front = node;
        node->front = nullptr;
        head = node;
    }

public:
    LRUCache(int capacity) {
        size = 0;
        cap = capacity;
        hashmap.clear();
        head = tail = nullptr;
    }

    int get(int key) {
        if(head== nullptr){
            return -1;
        }
        auto it = hashmap.find(key);
        if(it!=hashmap.end()){
            Node* now = it->second;
            pushFront(now);
            return it->second->val;
        } else{
            return -1;
        }

    }

    void put(int key, int value) {
//        cout<<"*"<<hashmap.size()<<endl;
        auto it = hashmap.find(key);
        if(it!=hashmap.end()){
            ///对于节点的位置要进行分析


            ///发现在cache中有该缓存，则将该节点放在双链表头部
            Node* now = it->second;
            now->val = value;
            pushFront(now);
        } else{
            if(hashmap.size()==cap){
                ///如果当前缓存达到了最大容量,则淘汰最长时间未被使用的，即tail

                if(tail!= nullptr){
                    int tmp = tail->key;

                    Node* delNode = tail;

                    ///这一步很重要
                    if(tail->front!=nullptr){
                        tail->front->next = tail->next;
                    }

                    tail = tail->front;

                    if(delNode!= nullptr){
                        delete delNode;
                    }


                    ///删除节点
                    hashmap.erase(hashmap.find(tmp));
//                    cout<<"**"<<hashmap.size()<<endl;

                }

            }
            auto newNode = new Node(value,key);
            pushFront(newNode);
            hashmap.insert(make_pair(key,newNode));
        }
    }
};

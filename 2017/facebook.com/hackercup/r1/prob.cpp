#include <algorithm>
#include <cassert>
#include <cstdio>
#include <vector>
using namespace std;

const int inf = 0x3f3f3f3f;

class SplayTree{
    public:
    class SplayNode{
        public:
        int key;
        int value;
        int score;
        int nsize;
        int sum;
        int maximum;
        int delta;
        SplayNode *parent;
        SplayNode *child[2];
        SplayNode(const int k, const int v, const int s) : key(k), value(v), score(s), nsize(1), sum(v), maximum(s), delta(0) {
            this->parent = nullptr;
            this->child[0] = nullptr;
            this->child[1] = nullptr;
        }
        ~SplayNode(){
            if (this->child[0] != nullptr) {
                delete this->child[0];
            }
            if (this->child[1] != nullptr) {
                delete this->child[1];
            }
        }
        int get_child_id() const { if (this->parent == nullptr) return -1;
            if (this == this->parent->child[0]) return 0;
            if (this == this->parent->child[1]) return 1;
            assert(false);
            return -1;
        }
        void flush(){
            // customized operation - interval increment
            if (this->delta != 0) {
                this->score += this->delta;
                this->maximum += this->delta;
                if (this->child[0] != nullptr) {
                    this->child[0]->delta += this->delta;
                }
                if (this->child[1] != nullptr) {
                    this->child[1]->delta += this->delta;
                }
                this->delta = 0;
            }
        }
        void update() {
            this->nsize = 1;
            this->sum = this->value;
            this->maximum = this->score;
            for (int i = 0; i < 2; ++i) {
                if (this->child[i] != nullptr) {
                    this->nsize += this->child[i]->nsize;
                    this->child[i]->parent = this;
                    // customized operation - cache minimum
                    this->sum += this->child[i]->sum;
                    this->maximum = std::max(this->child[i]->maximum + this->child[i]->delta, this->maximum);
                }
            }
        }
        SplayNode* rotate(const int cid) {
            this->flush();
            this->child[cid]->flush();
            // rotate operation
            SplayNode *node = this->child[cid];
            SplayNode *temp = node->child[cid ^ 1];
            node->child[cid ^ 1] = this;
            this->child[cid] = temp;
            // update grandparent
            SplayNode *grandparent = this->parent;
            if (grandparent != nullptr) {
                grandparent->child[this->get_child_id()] = node;
            }
            // update node values
            this->update();
            node->update();
            if (grandparent != nullptr) {
                grandparent->update();
            } else {
                node->parent = nullptr;
            }
            return node;
        }
        SplayNode* insert(const int key, const int value, const int score) {
            this->flush();
            SplayNode *nodeptr;
            if (key < this->key) {
                if (this->child[0] != nullptr) {
                    nodeptr = this->child[0]->insert(key, value, score);
                } else {
                    nodeptr = new SplayNode(key, value, score);
                    this->child[0] = nodeptr;
                }
            } else if (key > this->key) {
                if (this->child[1] != nullptr) {
                    nodeptr = this->child[1]->insert(key, value, score);
                } else {
                    nodeptr = new SplayNode(key, value, score);
                    this->child[1] = nodeptr;
                }
            } else {
                assert(false);
            }
            this->update();
            return nodeptr;
        }
        SplayNode* select(const int key) {
            //this->flush();
            if (key < this->key) {
                if (this->child[0] != nullptr) {
                    SplayNode* nodeptr = this->child[0]->select(key);
                    if (nodeptr != nullptr) {
                        return nodeptr;
                    } else {
                        return this;
                    }
                } else {
                    return this;
                }
            } else if (key > this->key) {
                if (this->child[1] != nullptr) {
                    return this->child[1]->select(key);
                } else {
                    return nullptr;
                }
            } else {
                return this;
            }
        }
        SplayNode* prev() {
            if (this->child[0] != nullptr) {
                //this->flush();
                SplayNode* foo = this->child[0];
                while (foo->child[1] != nullptr) {
                    //foo->flush();
                    foo = foo->child[1];
                }
                //foo->flush();
                return foo;
            } else {
                SplayNode* foo = this;
                while (foo->parent != nullptr) {
                    if (foo->get_child_id() == 0) {
                        foo = foo->parent;
                    } else {
                        return foo->parent;
                    }
                }
                return nullptr;
            }
        }
        void show() {
            this->flush();
            if (this->child[0] != nullptr) {
                this->child[0]->show();
            }
            fprintf(stderr, "%d, %d, %d", this->key, this->value, this->score);
            if (this->parent != nullptr) {
                if (this->get_child_id() == 0) {
                    fprintf(stderr, " -(%d)", this->parent->key);
                } else {
                    fprintf(stderr, " (%d)-", this->parent->key);
                }
            } else {
                fprintf(stderr, " (nullptr)");
            }
            fprintf(stderr, "\n");
            if (this->child[1] != nullptr) {
                this->child[1]->show();
            }
        }
    } *root;
    SplayTree() {
        this->root = nullptr;
    }
    ~SplayTree() {
        if (this->root != nullptr) {
            delete this->root;
        }
    }
    void splay(SplayNode *node) {
        this->splay(node, &this->root);
    }
    void splay(SplayNode *node, SplayNode **destination) {
        while (node != *destination) {
            if (node->parent == nullptr) {
                assert(false);
            }
            if (node->parent != *destination) {
                //double rotate
                if (node->parent->parent == nullptr) {
                    assert(false);
                }
                int cid = node->get_child_id();
                if (cid == node->parent->get_child_id()) {
                    node->parent->parent->rotate(cid);
                    node->parent->rotate(cid);
                } else {
                    node->parent->rotate(cid);
                    node->parent->rotate(cid ^ 1);
                }
                if (node->parent == nullptr) {
                    this->root = node;
                }
            } else {
                //single rotate
                node->parent->rotate(node->get_child_id());
                if (node->parent == nullptr) {
                    this->root = node;
                }
            }
        }
        while (node->parent != nullptr) {
            node->parent->update();
            node = node->parent;
        }
    }
    void insert(const int key, const int value, const int score) {
        if (this->root != nullptr) {
            SplayNode *nodeptr = this->root->insert(key, value, score);
            this->splay(nodeptr);
        } else {
            this->root = new SplayNode(key, value, score);
        }
    }
    void erase(SplayNode *node) {
        node->flush();
        while (true) {
            if (node->child[0] != nullptr) {
                SplayNode *candidate = node->child[0];
                candidate->flush();
                while (candidate->child[1] != nullptr) {
                    candidate = candidate->child[1];
                    candidate->flush();
                }
                node->key = candidate->key;
                node->value = candidate->value;
                node->score = candidate->score;
                node = candidate;
            } else if (node->child[1] != nullptr) {
                SplayNode *candidate = node->child[1];
                candidate->flush();
                while (candidate->child[0] != nullptr) {
                    candidate = candidate->child[0];
                    candidate->flush();
                }
                node->key = candidate->key;
                node->value = candidate->value;
                node->score = candidate->score;
                node = candidate;
            } else {
                if (node->parent != nullptr) {
                    node->parent->child[node->get_child_id()] = nullptr;
                    SplayNode *temp = node->parent;
                    while (temp != nullptr) {
                        temp->update();
                        temp = temp->parent;
                    }
                    this->splay(node->parent);
                } else {
                    this->root = nullptr;
                }
                delete node;
                break;
            }
        }
    }
    SplayNode *select(const int key) {
        if (this->root != nullptr) {
            return this->root->select(key);
        } else {
            return nullptr;
        }
    }
    void show() {
        fprintf(stderr, "----Splay Tree----\n");
        if (this->root != nullptr) {
            this->root->show();
        } else {
            fprintf(stderr, "nil\n");
        }
    }
};

class MagicBox {
    private:
    SplayTree *splaytree;
    public:
    MagicBox() {
        this->splaytree = new SplayTree();
        this->splaytree->insert(-inf, 0, 0);
        this->splaytree->insert(inf, 0, 0);
    }
    ~MagicBox() {
        delete this->splaytree;
    }
    void add(const int y, const int r) {
        SplayTree::SplayNode *nodeptr = this->splaytree->select(y);
        if (nodeptr->key != y) {
            this->splaytree->splay(nodeptr->prev());
            this->splaytree->splay(this->splaytree->select(y + r + 1), &this->splaytree->root->child[1]);
            int score = 0;
            if (this->splaytree->root->child[1]->child[0] != nullptr) {
                score += this->splaytree->root->child[1]->child[0]->sum;
            }
            this->splaytree->insert(y, 0, score);
            nodeptr = this->splaytree->root;
        }
        this->splaytree->splay(nodeptr);
        nodeptr->value += 1;
        nodeptr->update();
        this->splaytree->splay(this->splaytree->select(y - r)->prev());
        this->splaytree->splay(this->splaytree->select(y + 1), &this->splaytree->root->child[1]);
        this->splaytree->root->child[1]->child[0]->delta += 1;
        this->splaytree->root->child[1]->update();
        this->splaytree->root->update();
    }
    void sub(const int y, const int r) {
        SplayTree::SplayNode *nodeptr = this->splaytree->select(y);
        assert(nodeptr->key == y);
        this->splaytree->splay(nodeptr);
        nodeptr->value -= 1;
        nodeptr->update();
        if (nodeptr->value == 0) {
            //fprintf(stderr, "erase key = %d\n", nodeptr->key);
            this->splaytree->erase(nodeptr); 
            //this->splaytree->show();
        }
        this->splaytree->splay(this->splaytree->select(y - r)->prev());
        this->splaytree->splay(this->splaytree->select(y + 1), &this->splaytree->root->child[1]);
        if (this->splaytree->root->child[1]->child[0] != nullptr) {
            this->splaytree->root->child[1]->child[0]->delta -= 1;
            this->splaytree->root->child[1]->update();
            this->splaytree->root->update();
        }
    }
    int max() {
        //this->splaytree->show();
        //fprintf(stderr, "max = %d\n", this->splaytree->root->maximum + this->splaytree->root->delta);
        return this->splaytree->root->maximum + this->splaytree->root->delta;
    }
};

struct Zombie {
    int x, y;
};

int exclusive(const vector<Zombie> &zombies, const int r, const int ax, const int ay) {
    const int n = zombies.size();
    MagicBox mb;
    int foo = 0, goo = 0;
    for (int lef = 0, rig = 0; rig < n; ) {
        const int x = zombies[rig].x;
        //remove
        while(lef < n && zombies[lef].x < x - r) {
            if (ax <= zombies[lef].x && zombies[lef].x <= ax + r && ay <= zombies[lef].y && zombies[lef].y <= ay + r) {
                lef++;
            } else {
                mb.sub(zombies[lef++].y, r);
            }
        }
        while(rig < n && zombies[rig].x == x) {
            if (ax <= zombies[rig].x && zombies[rig].x <= ax + r && ay <= zombies[rig].y && zombies[rig].y <= ay + r) {
                goo += 1;
                rig++;
            } else {
                mb.add(zombies[rig++].y, r);
            }
        }
        //fprintf(stderr, "x = %d\n", x);
        foo = max(mb.max(), foo);
    }
    //fprintf(stderr, "ax = %d, ay = %d, foo = %d, goo = %d\n", ax, ay, foo, goo);
    return foo + goo;
}

inline int mycompare(const Zombie &lhs, const Zombie &rhs) {
    if (lhs.x != rhs.x) return lhs.x < rhs.x;
    return lhs.y < rhs.y;
}

int solution(vector<Zombie> &zombies, const int r) {
    const int n = zombies.size();
    sort(zombies.begin(), zombies.end(), mycompare);
    int foo = 0;
    for (int i = 0; i < n; ++i) {
        if (i > 0 && zombies[i].x == zombies[i - 1].x) continue;
        for (int j = 0; j < n; ++j) {
            foo = max(exclusive(zombies, r, zombies[i].x, zombies[j].y), foo);
        }
    }
    return foo;
}

int main(){
    int case_num;
    scanf("%d", &case_num);
    for (int case_id = 1; case_id <= case_num; ++case_id) {
        int n, r;
        scanf("%d%d", &n, &r);
        vector<Zombie> zombies(n, Zombie());
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &zombies[i].x, &zombies[i].y);
        }
        printf("Case #%d: %d\n", case_id, solution(zombies, r));
    }
    return 0;
}

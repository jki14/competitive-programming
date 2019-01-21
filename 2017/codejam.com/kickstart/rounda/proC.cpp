#include <iostream>
#include <vector>
using namespace std;

class Vector3d {
    private:
        int foo[3];
    public:
        Vector3d(const int x) {
            this->foo[0] = x;
            this->foo[1] = x;
            this->foo[2] = x;
        }
        Vector3d(const int x, const int y, const int z) {
            this->foo[0] = x;
            this->foo[1] = y;
            this->foo[2] = z;
        }
        Vector3d(const Vector3d &rhs) {
            this->foo[0] = rhs[0];
            this->foo[1] = rhs[1];
            this->foo[2] = rhs[2];
        }
        const int& operator [] (const int k) const{
            return this->foo[k];
        }
        int& operator [] (const int k) {
            return this->foo[k];
        }
        Vector3d operator + (const Vector3d &rhs) const{
            Vector3d tmp(*this);
            tmp[0] += rhs[0];
            tmp[1] += rhs[1];
            tmp[2] += rhs[2];
            return tmp;
        }

        Vector3d operator - (const Vector3d &rhs) const{
            Vector3d tmp(*this);
            tmp[0] -= rhs[0];
            tmp[1] -= rhs[1];
            tmp[2] -= rhs[2];
            return tmp;
        }
        Vector3d operator * (const Vector3d &rhs) const{
            Vector3d tmp(*this);
            tmp[0] *= rhs[0];
            tmp[1] *= rhs[1];
            tmp[2] *= rhs[2];
            return tmp;
        }

};

class Star {
    private:
        Vector3d center;
        int radius;
    public:
        Star(const int x, const int y, const int z, const int r) : center(x, y, z), radius(r) {
            //pass
        }
        Vector3d GetCenter() const{
            return this->center;
        }
        int GetRadius() const{
            return this->radius;
        }
};

class Box {
    private:
        Vector3d zero;
        Vector3d expand;
        static const Vector3d orientation[8];
    public:
        Box(const Vector3d &vertex, const Vector3d &expand, const int vertexId = 0) : zero(vertex - expand * this->orientation[vertexId]), expand(expand) {
            //pass
        }
        Vector3d GetVertex(const int vertexId = 0) const {
            return this->zero + this->expand * this->orientation[vertexId];
        }
        int GetLongestDiff() const {
            return max(max(this->expand[0], this->expand[1]), this->expand[2]);
        }
        bool IsContained(const Vector3d &point) const {
            Vector3d bounder(this->zero + this->expand);
            for (int i = 0; i < 3; ++i) {
                if (point[i] < this->zero[i]
                        || point[i] > bounder[i])
                    return false;
            }
            return true;
        }
};

const Vector3d Box::orientation[8] = {
    Vector3d(0, 0, 0),
    Vector3d(1, 1, 1),
    Vector3d(1, 0, 0),
    Vector3d(0, 1, 1),
    Vector3d(1, 0, 1),
    Vector3d(0, 1, 0),
    Vector3d(0, 0, 1),
    Vector3d(1, 1, 0)
};


class Cube : public Box {
    public:
        Cube (const Vector3d &vertex, const int length, const int vertexId = 0) : Box (vertex, Vector3d(length, length, length), vertexId) {
            //pass
        }
};

static bool Covered(const int length, const Box &box, const vector<Cube> &cubeList) {
    for (int p = 0; p < 8; ++p) {
        for (int q = p + 1; q < 8; ++q) {
            Cube cubex(box.GetVertex(p), length, p);
            Cube cubey(box.GetVertex(q), length, q);
            bool negative = false;
            for (const auto &cube : cubeList) {
                if (cubex.IsContained(cube.GetVertex(0))
                        && cubex.IsContained(cube.GetVertex(1)))
                    continue;
                if (cubey.IsContained(cube.GetVertex(0))
                        && cubey.IsContained(cube.GetVertex(1)))
                    continue;
                negative = true;
                break;
            }
            if (!negative) return true;
        }
    }
    return false;
}

static int BinarySearch(const Box &box, const vector<Cube> &cubeList) {
    int lef = 1, rig = box.GetLongestDiff();
    while (lef <= rig) {
        int mid = (lef + rig) / 2;
        if (Covered(mid, box, cubeList)) {
            if (mid == lef || !Covered(mid - 1, box, cubeList)) return mid;
            rig = mid - 1;
        } else {
            lef = mid + 1;
        }
    }
    //Never Exec Branch
    return -1;
}

int SpaceCubes(const vector<Star> &starList) {
    //TODO: check if starList is valid
    int n = starList.size();
    vector<Cube> cubeList;
    for (int i = 0; i < n; ++i) {
        Cube cube(starList[i].GetCenter() - Vector3d(starList[i].GetRadius()), starList[i].GetRadius() * 2);
        cubeList.push_back(cube);
    }
    Vector3d vertex0(cubeList[0].GetVertex(0));
    Vector3d vertex1(cubeList[0].GetVertex(1));
    for (int i = 1; i < n; ++i) {
        for(int k = 0; k < 3; ++k) {
            vertex0[k] = min(cubeList[i].GetVertex(0)[k], vertex0[k]);
            vertex1[k] = max(cubeList[i].GetVertex(1)[k], vertex1[k]);
        }
    }
    Box box(vertex0, vertex1 - vertex0);
    return BinarySearch(box, cubeList);
}

int main(){
    int c;
    cin >> c;
    for (int i = 0; i < c; ++i) {
        int n;
        cin >> n;
        vector<Star> a;
        for (int j = 0; j < n; ++j) {
            int x, y, z, r;
            cin >> x >> y >> z >> r;
            a.push_back(Star(x, y, z, r));
        }
        cout << "Case #" << i + 1 << ": " << SpaceCubes(a) << endl;
    }
    return 0;
}

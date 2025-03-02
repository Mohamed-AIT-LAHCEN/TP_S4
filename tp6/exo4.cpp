#include <iostream>
#include <memory>

using namespace std;

struct MemoryBlock {
    int size;

    MemoryBlock(int s) : size(s) {
        cout << "Bloc de mémoire alloué de " << size << " unités." << endl;
    }

    ~MemoryBlock() {
        cout << "Bloc de mémoire de " << size << " unités libéré." << endl;
    }
};

unique_ptr<MemoryBlock> mergeBlocks(unique_ptr<MemoryBlock> block1, unique_ptr<MemoryBlock> block2) {
    int newSize = block1->size + block2->size;
    block1.reset(); // Release the first block
    block2.reset(); // Release the second block
    return make_unique<MemoryBlock>(newSize); // Return a new merged block
}

int main() {
    unique_ptr<MemoryBlock> block1 = make_unique<MemoryBlock>(100);
    unique_ptr<MemoryBlock> block2 = make_unique<MemoryBlock>(200);

    unique_ptr<MemoryBlock> mergedBlock = mergeBlocks(move(block1), move(block2));
    cout << "Fusion des deux blocs : " << mergedBlock->size << " unités." << endl;

    // Memory will be automatically released when unique_ptr goes out of scope
    return 0;
}
/* Korovin Danil st128737@student.spbu.ru
   LabWork3
*/
#include "circ_list.h"
#include <gtest/gtest.h>
#include <numeric>


TEST(ConstructorTest, DefaultConstructor)
{
    circ_list<int> l;
    EXPECT_TRUE(l.empty());
    EXPECT_EQ(l.size(), 0);
}

TEST(ConstructorTest, InitializerListConstructor)
{
    circ_list<int> l = {1, 2, 3};
    EXPECT_EQ(l.size(), 3);
    EXPECT_EQ(l.front(), 1);
    EXPECT_EQ(l.back(), 3);
}

TEST(ConstructorTest, CopyConstructor)
{
    circ_list<int> l1 = {1, 2};
    circ_list<int> l2 = l1;
    EXPECT_EQ(l2.size(), 2);
    EXPECT_EQ(l2.front(), 1);
    EXPECT_EQ(l2.back(), 2);
}

TEST(ConstructorTest, MoveConstructor)
{
    circ_list<int> l1 = {1, 2};
    circ_list<int> l2 = std::move(l1);
    EXPECT_EQ(l2.size(), 2);
    EXPECT_EQ(l2.front(), 1);
    EXPECT_EQ(l2.back(), 2);
    EXPECT_TRUE(l1.empty());
}

TEST(ConstructorTest, Destructor)
{
    circ_list<int>* l = new circ_list<int> {1, 2, 3};
    EXPECT_EQ(l->size(), 3);
    delete l;
}

TEST(IteratorsTest, Iterators)
{
    circ_list<int> l = {1, 2};
    auto it = l.begin();
    EXPECT_EQ(*it, 1);
    ++it;
    EXPECT_EQ(*it, 2);
    ++it;
    EXPECT_EQ(*it, 1);
    ++it;
    EXPECT_EQ(*it, 2);
}

TEST(IteratorsTest, ConstIterators)
{
    const circ_list<int> l = {1, 2};
    auto it = l.begin();
    EXPECT_EQ(*it, 1);
    ++it;
    EXPECT_EQ(*it, 2);
    ++it;
    EXPECT_EQ(*it, 1);
    ++it;
    EXPECT_EQ(*it, 2);

}

TEST(IteratorsTest, Begin)
{
    circ_list<int> l = {1, 2, 3};
    auto it = l.begin();
    EXPECT_EQ(*it, 1);
}

TEST(IteratorsTest, ConstBegin)
{
    const circ_list<int> l = {1, 2, 3};
    auto it = l.begin();
    EXPECT_EQ(*it, 1);
}

TEST(IteratorsTest, Dereference)
{
    circ_list<int> l = {1, 2};
    auto it = l.begin();
    EXPECT_EQ(*it, 1);
    *it = 5;
    EXPECT_EQ(*it, 5);
}

TEST(IteratorsTest, Increment)
{
    circ_list<int> l = {1, 2, 3};
    auto it = l.begin();
    EXPECT_EQ(*it, 1);
    ++it;
    EXPECT_EQ(*it, 2);
    it++;
    EXPECT_EQ(*it, 3);
}

TEST(IteratorsTest, Decrement)
{
    circ_list<int> l = {1, 2, 3};
    auto it = l.begin();
    EXPECT_EQ(*it, 1);
    --it;
    EXPECT_EQ(*it, 3);
    it--;
    EXPECT_EQ(*it, 2);
}

TEST(IteratorsTest, Equality)
{
    circ_list<int> l = {1, 2, 3};
    auto it1 = l.begin();
    auto it2 = l.begin();
    EXPECT_EQ(it1, it2);
    ++it2;
    EXPECT_NE(it1, it2);
}

TEST(IteratorsTest, SwapIterator)
{
    circ_list<int> l = {1, 2};
    auto it1 = l.begin();
    auto it2 = it1;
    ++it2;
    it1.swap(it2);
    EXPECT_EQ(*it1, 2);
    EXPECT_EQ(*it2, 1);
}

TEST(FuncTest, Size)
{
    circ_list<int> l = {1, 2, 3};
    EXPECT_EQ(l.size(), 3);
}

TEST(FuncTest, Front_and_Back)
{
    circ_list<int> l = {1, 2};
    EXPECT_EQ(l.front(), 1);
    EXPECT_EQ(l.back(), 2);
}

TEST(FuncTest, Pop_Front)
{
    circ_list<int> l = {1, 2, 3};
    l.pop_front();
    EXPECT_EQ(l.size(), 2);
    EXPECT_EQ(l.front(), 2);

}

TEST(FuncTest, Pop_Back)
{
    circ_list<int> l = {1, 2, 3};
    l.pop_back();
    EXPECT_EQ(l.size(), 2);
    EXPECT_EQ(l.back(), 2);
}

TEST(FuncTest, CopyAssignment)
{
    circ_list<int> l1 = {1, 2};
    circ_list<int> l2;
    l2 = l1;
    EXPECT_EQ(l2.size(), 2);
    EXPECT_EQ(l2.front(), 1);
    EXPECT_EQ(l2.back(), 2);
}

TEST(FuncTest, MoveAssignment)
{
    circ_list<int> l1 = {1, 2};
    circ_list<int> l2;
    l2 = std::move(l1);
    EXPECT_EQ(l2.size(), 2);
    EXPECT_EQ(l2.front(), 1);
    EXPECT_EQ(l2.back(), 2);
    EXPECT_TRUE(l1.empty());
}

TEST(FuncTest, Find)
{
    circ_list<int> l = {1, 2, 3};
    auto it = l.find(2);
    EXPECT_EQ(*it, 2);
    it = l.find(4);
    EXPECT_EQ(it, l.end());
}

TEST(FuncTest, Copy)
{
    circ_list<int> l1 = {1, 2, 3};
    circ_list<int> l2;
    l2.copy(l1);
    EXPECT_EQ(l2.size(), 3);
    EXPECT_EQ(l2.front(), 1);
    EXPECT_EQ(l2.back(), 3);
}

TEST(FuncTest, Compare)
{
    circ_list<int> l1 = {1, 2, 3};
    circ_list<int> l2 = {1, 2, 3};
    circ_list<int> l3 = {1, 2};
    EXPECT_TRUE(l1 == l2);
    EXPECT_FALSE(l1 == l3);
    EXPECT_TRUE(l1 != l3);
}

TEST(FuncTest, ReverseCopy)
{
    circ_list<int> l1 = {1, 2, 3};
    circ_list<int> l2;
    l2.reverse_copy(l1);
    EXPECT_EQ(l2.size(), 3);
    EXPECT_EQ(l2.front(), 3);
    EXPECT_EQ(l2.back(), 1);
}


TEST(OperationsTest, Push_Front)
{
    circ_list<int> l;
    l.push_front(1);
    l.push_front(2);
    EXPECT_EQ(l.front(), 2);
    EXPECT_EQ(l.back(), 1);
}

TEST(OperationsTest, Push_Back)
{
    circ_list<int> l;
    l.push_back(1);
    l.push_back(2);
    EXPECT_EQ(l.front(), 1);
    EXPECT_EQ(l.back(), 2);
}

TEST(OperationsTest, Clear)
{
    circ_list<int> l = {1, 2};
    l.clear();
    EXPECT_TRUE(l.empty());
}

TEST(OperationsTest, Insert)
{
    circ_list<int> l = {2, 3};
    auto it = l.begin();
    l.insert(it, 1);
    EXPECT_EQ(l.size(), 3);
    it = l.begin();
    EXPECT_EQ(*it, 1);
    ++it;
    EXPECT_EQ(*it, 2);
    ++it;
    EXPECT_EQ(*it, 3);
}

TEST(OperationsTest, Erase)
{
    circ_list<int> l = {1, 2, 3};
    auto it = l.begin();
    ++it;
    l.erase(it);
    EXPECT_EQ(l.size(), 2);
    it = l.begin();
    EXPECT_EQ(*it, 1);
    ++it;
    EXPECT_EQ(*it, 3);

}

TEST(ExceptionsTest, Exceptions)
{
    circ_list<int> l;
    EXPECT_THROW(l.front(), std::out_of_range);
    EXPECT_THROW(l.back(), std::out_of_range);
    EXPECT_THROW(l.pop_front(), std::out_of_range);
    EXPECT_THROW(l.pop_back(), std::out_of_range);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

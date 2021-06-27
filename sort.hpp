#include <array>

template <class T, size_t N>
void sort(std::array<T, N> &array)
{
    std::map<T, size_t> count{};
    for (const auto &element : array)
    {
        count[element]++;
    }
    for (auto &element : array)
    {
        auto countBegin = count.begin();
        element = countBegin->first;
        countBegin->second--;
        if (countBegin->second == 0)
        {
            count.erase(countBegin);
        }
    }
}
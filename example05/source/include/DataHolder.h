//
// Created by jperme on 3/10/25.
//

#ifndef DATAHOLDER_H
#define DATAHOLDER_H
#include <iostream>
#include <ostream>
#include <vector>

class DataHolder {
    public:
        void setData(const std::vector<int>& data)  {
            m_data = data;
            std::cout << "set data with l-value reference called." << std::endl;
        }
        void setData(std::vector<int>&& data) {
            m_data = std::move(data);
            std::cout << "set data with r-value reference called." << std::endl;
        }
private:
    std::vector<int> m_data;
};


#endif //DATAHOLDER_H

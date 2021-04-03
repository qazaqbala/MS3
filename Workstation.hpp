//
//  Workstation.hpp
//  Assignment3
//
//  Created by Temirlan Tolen  on 2021-04-03.
//

#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H

#include <iostream>
#include <deque>
#include <string>

//local file directives
#include "Station.h"
#include "CustomerOrder.h"

namespace sdds{


class Workstation : public Station
{
private:
    std::deque<CustomerOrder> m_pending;
    std::deque<CustomerOrder> m_completed;
    std::deque<CustomerOrder> m_incomplete;
    
    std::deque<CustomerOrder> m_orders;
    Workstation* m_pNextStation;
public:
    Workstation(const std::string& str);
    void fill(std::ostream& os);
    bool attemptToMoveOrder();
    void setNextStation(Workstation* station);
    const Workstation* getNextStation() const;
    void display(std::ostream& os) const;
    Workstation& operator+=(CustomerOrder&& newOrder);
};
}
#endif /* SDDS_WORKSTATION_H */

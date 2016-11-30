#ifndef _C_MOVELIST_H_
#define _C_MOVELIST_H_

#include <iostream>
#include <vector>

#include "CMove.h"

/***************************************************************
 * declaration of CMoveList
 *
 * This is a wrapper for the std::vector class.
 * It contains an array of moves.
 ***************************************************************/

class CMoveList
{
    public:
        CMoveList()
        {
            // Pre-allocate space for a large number of moves.
            // This is a slight optimization.
            m_moveList.reserve(10000);
            m_moveList_capture.reserve(100);
        }

        friend std::ostream& operator <<(std::ostream &os, const CMoveList &rhs);

        void push_back(const CMove& move)
        {
            m_moveList.push_back(move);
        }

        void push_back_capture(const CMove& move)
        {
            m_moveList_capture.push_back(move);
        }

        void clear()
        {
            m_moveList.clear();
            m_moveList_capture.clear();

        }

        unsigned int size() const
        {
            return m_moveList.size();

        }
        unsigned int size_capture() const
        {
            return m_moveList_capture.size();
        }

        const CMove & operator [] (unsigned int ix) const { return m_moveList_capture[ix]; }
        const CMove get_uncapture(int ix) { return m_moveList[ix]; }

    private:
        std::vector<CMove> m_moveList;
        std::vector<CMove> m_moveList_capture;

}; /* end of CMoveList */

#endif // _C_MOVELIST_H_


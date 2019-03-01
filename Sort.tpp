#ifndef SORT_T
#define SORT_T

#include <algorithm>
#include <string>
#include <QList>
#include "Enumerations.h"
#include "Spell.h"


// This class provides a template function that sorts based on a member value of the user's choice
// MemberType is a pointer to the specified member value, i.e. &Spell::name
// Note that the sorting is done via std::sort with an appropriate lambda function
template <typename MemberType>
class MemValComp {

	public:
		MemValComp(MemberType Spell::* mem_name) {
			member_name = mem_name;
		}
		bool doCompare(const Spell& s1, const Spell& s2) {
            if (s1.*member_name != s2.*member_name) {
                return s1.*member_name < s2.*member_name;
            } else {
                return s1.name < s2.name;
            }
		}

		void doSort(std::vector<Spell>& slist) {
			std::sort(slist.begin(), slist.end(), [this](Spell s1, Spell s2) {return doCompare(s1, s2);});
		}

	private:
		MemberType Spell::* member_name;
};

// This class does the same thing for two-level sorting
// MemberType1 corresponds to the first-level sort
template <typename MemberType1, typename MemberType2>
class MemValTwoComp {

    public:
        MemValTwoComp(MemberType1 Spell::* mem_name1, MemberType2 Spell::* mem_name2) {
            member_name1 = mem_name1;
            member_name2 = mem_name2;
        }

        bool doCompare(const Spell& s1, const Spell& s2) {
            if (s1.*member_name1 != s2.*member_name1) {
                return s1.*member_name1 < s2.*member_name1;
            } else if (s1.*member_name2 != s2.*member_name2) {
                return s1.*member_name2 < s2.*member_name2;
            } else {
                return s1.name < s2.name;
            }
        }

        void doSort(std::vector<Spell>& slist) {
            std::sort(slist.begin(), slist.end(), [this](Spell s1, Spell s2) {return doCompare(s1, s2);});
        }

    private:
        MemberType1 Spell::* member_name1;
        MemberType2 Spell::* member_name2;
};


#endif

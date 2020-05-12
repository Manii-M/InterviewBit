/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
/**
 * Approach is to see if interval will overlap or not .
 * there will be three cases
 * case 1 - if newinterval.start starts after the current.end which means not overlapping with the current
 * case 2 - if case 1 is not true then see the newinterval.end is smaller then the current.start 
 * which means newinterval has already finished before starting of the current interval hence no overlaps
 * case 3 - where both case fails so the overlapping is taking place 
 * we will take min start of new and current and max end of new current that will be the merged interval and keep doing the same thing.
*/
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval)
{

    if (intervals.size() == 0)
    {
        intervals.push_back(newInterval);
        return intervals;
    }
    int i = 0;
    vector<Interval> newIntervals;
    while (i < intervals.size())
    {
        Interval current = intervals[i];
        if (newInterval.start > current.end) // agar naya interval already aange se start ho rha h tooverlap nhi krega current ko
        {
            i++;
            newIntervals.push_back(current);
            continue;
        }
        else if (current.start > newInterval.end)
        {
            // intervals.insert(intervals.begin()+i,newInterval); insert in the new list so we'll have all the intervals
            //was not overlapping.
            newIntervals.push_back(newInterval);
            break;
        }
        else
        {
            newInterval.start = min(newInterval.start, current.start);
            newInterval.end = max(newInterval.end, current.end);

            //intervals.erase(intervals.begin()+i); //as erase takes O(n) timewe are taking new list and

            i++; //skipping the merged interval
        }
    }
    if (i == intervals.size())
    {
        newIntervals.push_back(newInterval); //when all intervals are merged and then lastly add this merged interval to newllist
    }
    else
    {
        while (i < intervals.size())
        {
            newIntervals.push_back(intervals[i]); //insert the remaining not merged interval in the new list TC O(n)
            i++;
        }
    }
    return newIntervals;
}

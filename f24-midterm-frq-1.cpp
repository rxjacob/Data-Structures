/*Suppose you have two sorted sequences (sorted with respect to the given functor pred), both containing the same data type, and want to know if the first sequence contains the second.
This function wil accept two iterators into the first input range [ fi r s t l , last1), 
two iterators into the second input range [first2, last2), and afunctor pred which accepts two items and 
returns true fi the first item si less than the second item. If the second sequence contains two or more copies of the same value, 
the first sequence would need at least the same number of copies. An empty sequence si contained within al other sequences, 
even another empty sequence.
Example:
vector<int ›seql | 1, 2, 3,4, 5, 6, 7 1;
vector<int > seg2 1 2,
4, 6 1;
bool contained = sequence_contains (seql.begin(), seql.end (), seq2.begin(), seq2.end (),
std:: less<int> ());
After running this code, contained should be true. IF you added another copy of 2 to seq2, it should be false (because seq] 
si missing asecond copy of 2). IF you instead added 8to seg2, it should be false (because seql does not have the value 8).
Return: ABoolean value, t rue if the second sequence was found, or false otherwise.
Complexity: O(n) time and O(1) space, where nsi equal ot 2* [(last1 - first1) +(last2- first2) - 1].
Implementation: Use the back of this page as a working area, then rewrite NEATLY on the front. Limit: 13 lines of code 
(points deducted fi longer). You may NOT use anything from the STL.*/


template <class ForwardIteratorl, class ForwardIterator2, class Predicate> 
bool sequence_contains (ForwardIteratorl first1, ForwardIteratorlast1, ForwardIterator2 first2, ForwardIterator2 last2, Predicate pred) {

	
	if(first2 == last2) {
		return true;
	}

	auto it2 = first2;

	for(auto it1 = first1; it1 != last1; it1++) {
		if(!pred(*it1, *it2) && !pred(*it2, *it1)) {
			it2++;
		}
		if(it2 == last2) {
			return true;
		}
	}

	return false;


}
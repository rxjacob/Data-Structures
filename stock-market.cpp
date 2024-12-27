/* Assume you are a market maker in an electronic stock exchange. 
You are given a stream of stock data which includes an identifier (a unique abbreviation that identifies the stock), 
the highest price that a buyer is willing to pay for the stock, and the lowest price that a seller is willing to sell the stock for. 
Each stock will only appear once in the stream and will have exactly one buyer and one seller.
The difference between the buyer and seller prices (i.e. buyer price - seller price) 
is the amount of money you earn from participating in the transaction. 
For instance, if a buyer is looking to buy EECS stock at $10 and a seller is offering EECS stock for $7, 
you can make a profit of $10 - $7 = $3 by buying from the seller at $7 and selling to the buyer for $10. 
If buyer price - seller price for a stock is negative, that stock should be ignored, 
as you would lose money if you tried to force a transaction!
You will implement the max_profit function (defined on the next page), 
which takes in a stream of stock information stock_in and a positive integer k. 
The function returns the maximum profit you can make from trading at most k stocks from the entire stream. 
It is possible for fewer than k transactions to occur, since not all stock transactions may produce positive profits 
(see example 2 on the back). The stock_in stream will contain data for a total of n stocks in the following format:
<stock_id1> <buy_price1> <sell_price1> <stock_id2> <buy_price2> <sell_price2> . . . <stock_id-n> <buy_price-n> <sell_price-n>
Constraints:
• Your solution should run in at most Θ(nlog(k)) time, where n is the number of stocks in the stream. 
The value of n will NOT be given to you.
• Your solution should use at most Θ(k) space.
• Youmayassumethat0<k≤n.
• Your solution should NOT make use of custom-defined structs or classes.
You may use the space below (as well as the previous page) as a working area. 
Write your code neatly in the space provided on the back of this page. The back of this page also includes additional examples.
Hint: The stock_in stream behaves like cin, and its contents can be extracted using operator». 
For example, if you had a string variable named stock_id and two double variables named buy_price and sell_price, 
you can read the contents of a single stock using the following line:
            stock_in » stock_id » buy_price » sell_price;
   
EECS 281 Midterm Exam Practice Uniqname:   Page 27 of 31
 Example 1: Given an integer k = 3 and the following stock_in stream:
EECS 5.00 2.00 BBB 81.00 79.00 IOE 42.50 42.00 EWRE 20.53 15.53 GGBL 22.15 21.15
You would return the value 10.00, since that is the maximum profit you can make from trading at most 3 stocks in the stream 
(EECS for a profit of $5 - $2 = $3, BBB for a profit of $81 - $79 = $2, and 
EWRE for a profit of $20.53 - $15.53 = $5) → $3 + $2 + $5 = $10.
Example 2: Given an integer k = 5 and the following stock_in stream:
DOW 14.41 12.41 COOL 45.19 46.83 LBME 16.63 16.61 FXB 3.14 8.11 NAME 12.79 12.00
You would return the value 2.81, since that is the maximum profit you can make from trading 
at most 5 stocks in the stream (DOW for a profit of $14.41 - $12.41 = $2, LBME for a profit of $16.63 - $16.61 = $0.02, and NAME for a 
profit of $12.79 - $12.00 = $0.79) → $2 + $0.02 + $0.79 = $2.81. Even though you are allowed to trade up to 5 stocks, only 3 are traded 
because the buyer prices of COOL and FXB are lower than their respective seller prices.
Complexity: At most Θ(n log(k)) time and Θ(k) space (see "Constraints" on previous page). 
Implementation: Write your code neatly in the space below. Limit: 25 lines of code (points deducted if
longer). You MAY use anything in the STL. */

#include <iostream>
#include <queue>
#include <sstream>

using namespace std;



double max_profit(istream &stock_in, int k) {

	priority_queue<double, vector<double>, greater<double>> pq;


	string stock_id;
	double buy_price;
	double sell_price;

	while(stock_in >> stock_id) {
		stock_in >> buy_price;
		stock_in >> sell_price;
		double profit = buy_price - sell_price;
		if(profit > 0) {
			pq.push(profit);
		}
		if(static_cast<int>(pq.size()) > k) {
			pq.pop();
		}
	}

	double sum = 0;
	while(!pq.empty()) {
		sum += pq.top();
		pq.pop();
	}

	return sum;
}



int main() {
	string str = "EECS 5.00 2.00 BBB 81.00 79.00 IOE 42.50 42.00 EWRE 20.53 15.53 GGBL 22.15 21.15";
	stringstream ss(str);

	cout << max_profit(ss, 3) << endl;
}


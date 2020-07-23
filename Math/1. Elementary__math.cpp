// Author : Abdallah Hemdan
// For Hassanosama, ICPC next year ISA.
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <bits\stdc++.h>
#define vll vector<ll>
#define vi vector<int>
#define sz size()
#define pii pair<int, int>
#define IO ios_base::sync_with_stdio(0), ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define all(v) ((v).begin()), ((v).end())
#define rall(v) ((v).rbegin()), ((v).rend())

using namespace std;
using ll = long long int;
using ld = long double;

int MOD = 1e9 + 7;
const double EPS = 1e-9;
const int oo = INT_MAX;
const ll OO = 1e18;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

ll GCD(ll a, ll b) { return ((!b) ? a : GCD(b, a % b)); }
ll LCM(ll a, ll b) { return a / (GCD(a, b)) * b; }

// 0 if (a = b), 1 if (a > b) ,  -1 if (b > a)
int comp_double(double a, double b)
{ 
	if (fabs(a - b) <= EPS)
		return 0;
	return a < b ? -1 : 1;
}

ll fastpow(ll b, ll e)
{
	if (!e)
		return 1;
	if (e & 1)
		return b * fastpow(b, e - 1);
	ll x = fastpow(b, e / 2);
	return x * x;
}

ll PowMod(ll bs, ll ex, ll M)
{
	if (!ex)
		return 1;
	ll p = PowMod((bs * bs) % M, ex >> 1, M);
	return (ex & 1) ? (p * bs) % M : p;
}

void Problem_1()
{
	ll n;
	cin >> n;
	ll ans = PowMod(1378, n, 10);
	cout << ans << endl;
}

void Problem_2()
{
	ll k, r;
	cin >> k >> r;
	ll noOfCoins = 1;
	while (true)
	{
		if ((k * noOfCoins) % 10 == 0 || (k * noOfCoins - r) % 10 == 0)
			break;
		noOfCoins++;
	}
	cout << noOfCoins << endl;
}

void Problem_3()
{
	ll A = 0, B = 0;
	ll n, ba;
	cin >> n >> ba;
	vll a(n);
	for (ll &i : a)
		cin >> i;
	reverse(all(a));
	for (int i = 0; i < n; i++)
		A += a[i] * pow(ba, i);

	ll m, bb;
	cin >> m >> bb;
	vll b(m);
	for (ll &i : b)
		cin >> i;
	reverse(all(b));
	for (int i = 0; i < m; i++)
		B += b[i] * pow(bb, i);

	if (A < B)
		puts("<");
	else if (A > B)
		puts(">");
	else
		puts("=");
}

void Problem_4()
{
	ll n;
	cin >> n;
	ll cnt = 0;
	while (n)
	{
		cnt += (n & 1);
		n >>= 1;
	}
	cout << cnt << endl;

	// Cool !!
	// cout << __builtin_popcountll(n)) << endl;
}

void Problem_5()
{
	cout << cnt << endl ll n, x;
	cin >> n >> x;
	int cnt = 0;
	for (int i = 1; i <= n; i++)		// iterate over all the rows
		if (x % i == 0 && x / i <= n) // check if this row is multiple of x, check the other multiple exists
			cnt++;
	;
}

vector<ll> Generate_Divisors_1(ll n)
{ // O(n)
	vector<ll> divs;
	for (int i = 1; i <= n; i++)
		if (n % i == 0)
			divs.push_back(i);
	return divs;
}

vector<ll> Generate_Divisors_2(ll n)
{ // O(sqrt(n))
	vector<ll> divs;
	ll i;
	for (i = 1; i * i <= n; i++)
	{
		if (n % i != 0)
			continue;
		divs.push_back(i);
		if (i * i == n)
			continue;
		divs.push_back(n / i);
	}
	sort(all(divs)); // O(nLog(n))
	return divs;
}

ll CountDivisors(ll n)
{ // O(sqrt(n))
	ll Cnt = 0, i;
	for (i = 1; i * i < n; i++)
		if (n % i == 0)
			Cnt += 2;
	if (i * i == n)
		Cnt++;
	return Cnt;
}

const int MAXN = 1e5 + 15;
ll Divs[MAXN];

void Div_count(ll n)
{
	for (int i = 1; i <= n; i++)
	{
		for (ll j = 2 * i; j <= n; j += i)
			Divs[j]++;
		Divs[i]++; // Divisor of myself
	}
}

// Basic Math session
void Basics()
{
	// C++ offers for us some ready-made functions like
	// floor, ceil, round, fabs, abs, sqrt, exp, log, log2, log10, pow, cos, cosh, acosh

	// to use them u need to include <cmath> lib
	// #include <cmath>

	// Rounding Values

	//round: nearest integer to x
	//floor : round down
	//ceil : round up
	//trunc : rounds toward zero(remove fraction)

	// replacement for ceil (double)
	// ceil(x, y) = (x+y-1) / y  (integer domain)

	// Double comparsion

	// • do not use float in competitve programming cuz it have some percision errors
	// Sometimes if u make float comparsion it'll fails
	double x = 4.7;
	if (x == 4.7)
		puts("Equal"); // fails!

	cout << fixed << setprecision(20) << x << endl;

	// so instead of it, we use comp_double()
	if (comp_double(x, 4.7) == 0)
		cout << "x equal 4.7" << endl;

	// # of digits
	// # digits = 1 + floor(log10(n))

	// fast power
	ll a = 5, b = 12;
	ll pw = fastpow(a, b); // O(logn)
	cout << pw << endl;

	// power mod (a ^ b) % MOD
	ll e = 5, c = 10000, mod = 1e9 + 7;
	ll ans = PowMod(e, c, mod);

	// Problems
	// 1. https://codeforces.com/contest/742/problem/A
	// given a number n, find the last digit in pow(1378,n)
	Problem_1();

	// 2. https://codeforces.com/contest/732/problem/A
	// each shavel cost k egy-pound and we have unlimited number of coins of cost 10 egy-pound
	// and only one coin of cost r-egy-pound
	// find the minimum number of coins we need to pay to buy shavels without any coin-back
	Problem_2();

	// 3. https://codeforces.com/contest/602/problem/A
	// Given 2 numbers in different bases, compare between them = | > | <
	Problem_3();

	// 4. https://codeforces.com/contest/579/problem/A
	// u can put any number of bacteria into the box. And each night, every bacterium in the box will split into two bacteria. You hope to see exactly x bacteria in the box at some moment.
	// What is the minimum number of bacteria u need to put into the box across those days ?
	Problem_4();

	// Modular Arithmetic

	// Suppose we r now 9 in 12 time system
	// what'll be the time after 4 hours, 17 hours
	// 9 + 4 = 13 = 1 + 12 = 1
	// 9 + 17 = 26 = 2 + (2 * 12)  = 2
	// so we can represent any number as N = r (rem) + m * c(cycles)
	// So % used to remove the cycles from our number

	// what if I ask u before 24 (2 * 12) hours ?
	// 9 = > 9 - 24 = -15h => hmm
	// • 15 % 12 = 3….          hmm, we r sure results should be 9 too.
	// • So fact  :  + ve is not as same - ve
	// So we have to fix it
	// (Fixing -ve) Rule
	// (a % n + n) % n
	// (-15 % 12 + 12) % 12 = (-3 + 12) % 12 = 9 % 12 = 9

	// List of facts about modulus

	// • a%n = 0 = > a divisible by n
	// • If a%n == b%n = > (a - b) % n = 0
	// • largest n such that a%n = b%n is n = b - a
	// • (a % n) % n = a % n
	// • (n ^ x) % n = 0 for any x > 0
	// • -a%n != a%n = > (3 % 12 = 3 vs - 3 % 12 = 9)
	// • ((-a%n) + (a%n)) % n = 0
	// • (a + b) % n = (a%n + b%n) % n
	// • (a + b + c + d) % n ?
	// • You can take mod of every one and sum
	// • or ((((a%n + (b%n)) % n + c%n) % n + d%n) % n
	// • x % (a + b) != x % a + x %b
	// • x % 10 [get the last digit].

	// Sometimes, u r sure final results <= n, but intermediate results overflow.
	// Take intermediate % x  | (x > n)
	// 1001 - 1111 + 153 = 43 ... let x = 44
	
	
	// Generate divisors

	// 1. Straight forward thinking
	ll n = 15;
	vector<ll> divs = Generate_Divisors_1(n);
	for (auto i : divs)
		cout << i << ' ';
	cout << endl;

	// 2. By observation
	// if we analysis 36
	// 1 * 36
	// 2 * 18
	// 3 * 12
	// 4 * 9
	// 6 * 6  ===> sqrt(36)
	// 9 * 4
	// 12 * 3
	// 18 * 2
	// 36 * 1

	// So we only need to traverse to sqrt(n)
	divs = Generate_Divisors_2(n);

	// Count divisors of a number n
	// What we'll change in Generate_Divisors() ??!
	ll cntOfDivisors = CountDivisors(n);

	// Count the number of divisors for each number from 1 to n
	Div_count(n);

	// 5. https://codeforces.com/problemset/problem/577/A
	Problem_5();
}


int main()
{
	IO;
#ifndef ONLINE_JUDGE
	freopen("In.txt", "r", stdin);
#else
	// freopen("input.in","r",stdin);
	// freopen("output.out","w",stdout);
#endif
	Basics();
}

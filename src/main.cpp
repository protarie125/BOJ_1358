#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int w, h, x, y, p;
	cin >> w >> h >> x >> y >> p;

	const auto& r = h / 2;

	auto ct = int{ 0 };
	while (0 < (p--)) {
		int px, py;
		cin >> px >> py;

		// left circle
		const auto& ldx = px - x;
		const auto& ldy = py - (y + r);
		const auto& ldist = ldx * ldx + ldy * ldy;
		const auto& inLc = ldist <= r * r;

		// right circle
		const auto& rdx = px - (x + w);
		const auto& rdy = py - (y + r);
		const auto& rdist = rdx * rdx + rdy * rdy;
		const auto& inRc = rdist <= r * r;

		// rect
		const auto& inRect =
			(x <= px) && (px <= (x + w)) &&
			(y <= py) && (py <= (y + h));

		if (inLc || inRc || inRect) {
			++ct;
		}
	}

	cout << ct;

	return 0;
}
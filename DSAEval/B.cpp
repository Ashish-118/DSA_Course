
#include <bits/stdc++.h>
using namespace std;

void solve(float v, float p, float target_p, float p_min, float p_max, int loop, int action = 1)
{

    if (p == target_p || loop == 1000)
    {
        cout << "Reached the goal or loop limit." << endl;
        cout << "Final Position: " << p << endl;
        cout << "Final Velocity: " << v << endl;
        return;
    }

    float v_next = v + 0.001 * action - 0.0025 * cos(3 * p);
    float p_next = p + v_next;

    cout << "Loop: " << loop << endl;
    cout << "Velocity: " << v_next << endl;
    cout << "Position: " << p_next << endl;

    if (p_next >= target_p || p_next >= p_max)
    {
        action = -1;
    }
    else if (p_next <= p_min)
    {
        v = 0;
        action = 1;
    }
    else
    {
        action = 1;
    }

    solve(v_next, p_next, target_p, p_min, p_max, loop + 1, action);
}

int main()
{

    float target_p, p_min, p_max, p_start;
    cout << "Enter target position, minimum position, maximum position, and start position: ";
    cin >> target_p >> p_min >> p_max >> p_start;

    float v = 0;
    float p = p_start;

    solve(v, p, target_p, p_min, p_max, 0);

    return 0;
}

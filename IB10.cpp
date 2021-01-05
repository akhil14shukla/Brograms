#include <bits/stdc++.h>
#include <stack>
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)

using namespace std;

int Substring(string A)
{
    unordered_map<char, int> m;
    queue<char> q1;
    int max = 1;
    for (int i = 0; i < A.size(); i++)
    {
        if (m.find(A[i]) == m.end())
        {
            m[A[i]] = i;
            // q1.push(A[i]);
        }
        else{
            if (max < m.size())
                max = m.size();
            i = m[A[i]];
            m.erase(m.begin(),m.end());
            // m[A[i]] = i
            
        }
        /*else if (q1.front() == A[i])
        {
            if (max < q1.size())
                max = q1.size();
            q1.pop();
            m.erase(A[i]);
            m[A[i]] = i;
            q1.push(A[i]);
        }
        else
        {
            if (max < q1.size())
                max = q1.size();
            m.erase(m.begin(), m.end());
            while (q1.size() != 0)
            {
                q1.pop();
            }
        }*/

    }
    if (max < m.size())
        max = m.size();
    return max;
}

int main()
{
    string A = "iMik7M0zSLAdEwWmWNIZNH9s5tq5XBBPkReJ7bE4YzrW2aoCxflomFGdR56ihWppWcI8G4uf6GiZDcby5kkippUtnhfIQes3tZtXnvGu6DTVf0qpAZm1mg5oBpRVIPEo2SHfvPCOV9LpBSP16eUJqZEMvhO8A9wcQxLuHcGJLp5eedZCd0r6K4ugkAtMiDwQpOmTJnGJDkf5kPeZfAbVgbqPrXHE9BC7heCu3PFG3ss1A3uoQpIGAmirlATMYWqeFh8KE9cHZ9rjQOArNVCRhzkQye6JsmIwgN33LqmKCdfc5VJmq95aulgYq4rvBqekUN7zkX9DwZRg2huLDlRtmfycepV0YV0503hB0TGJ14fs8SHfiKuzqi6Lzx1n47jl7nDybGQB8XxfQgpHn00qjaOWU6WsOlqeQftCgXnEX1vQDdJqyK5t90KcyK4LVupxv4zoSEdvlxlEzJcuBesFAqBIxkCTn9I1Wu2p55ItcAyXUuT1QzrIVFynvYvvkh5q72kBhXf8mqX6ZF0mN3uILfNuoXbI5iwdRbCx1wTHEwTKWwDnHXCQTh7sCt5PSlqhnHcyJUb1K2piBXBsVOCa0c1A09GQOs6ubIWfmuq4ZeJtmwGCFKv70W5y2HdjjHWoYMWycPLsHupk2aA6tlEQuOpGMrUW1fJBxuyQt7E9KLScvQ9qaXApddKqCj8ciZfyLPzyvUqfmKGrLDovRDFspT5ubjUMVeYZ742bAq0ELuDsXs67FyR1Kk2eULAKplkWRdNBQq1amSTcSMoW8cOWkiyv5zQ12hR2zmMDBxTTGXy8u8Tlur9dQnXu5SwAqsCpAOxkSNeRqzk7Iy05wUHnexylXyZyH2NSKu0YM5GcWxoPyS9hVayjYtWdeJ1z47w74J05xZZ4oM2l0rDgv9oQCKyhhPt3LVF6P6OGetqNcEqMRd3TQlxwyyC35d6Y6daRGlmv8zMcvHoC0aUlSM9eXQUfM5q9PFkWZLQspceuW2TuXbgeQsfhLwlBZ126oa7qNldkDmV9MgK5nqBs2n7MCnrcgsvRwI0QoYPZjOr9TWLmbImBZohHb0ks07qlchr9J5lx9bXdszPIS0zetGJ4b1O1Ad92V9r17EGS7kNwmsWNyL7R6XUN4HvJv2NQFQRide2fpX1HV2C4HDZNOj2rLVOzjAkB0IQuHts7aW8JwJbGMS9PD1RjsA7FPX1cYHpvFV5S45zkFhirRdXjBGS67GmNiNrDZaMSPMxf267eEIveFDSnqoDNAHpXFywGT9LSu2aQ6rLCZD0vDkOrIY9OBiJ13VBygWqOFx6p84wBfoQwE3UHvGOB4HiJjPxqGAA3WRCSO4fECvnKcMfy2mj1YUR2gVeMyBWUAcbTuobmpPMe7P3goNSqwC8fLUFhHrgcnlxHBhH9C1A17X9fYzZASmibYRhFlIh4LQAFwQUIDBmYzAmZ6Ql3yqmrnMEjsPdbkcjPy3hHXkehx3fp1I5dNmnvZx2ravEewm82vHOYOVnBbrsmQszujfWqzVJCepOlgNcnEdqD1D8h5pVraLvDql5jzrsFUHujVtL3qjO7p6WFe513KOfUhhmYk8KHNSPvDFrw6bXZvdNb0ZogkkSgQI3AjdmpJgzY3DSR6UmCRnehczTZJuZzEAJEVfy2AwI5JdIEmrEzWjfSfP8jTgHAJ9GKXaar1KdimLh85G9KEkFeCG8YTj0OtTvdkcH9FoN6iZEKmqp958j2TGfSKGYi8xBOQZeNdbslst363abrVBIasRzMIY948BaH9INr";
    int B = Substring(A);
    cout << B;
    return 0;
}

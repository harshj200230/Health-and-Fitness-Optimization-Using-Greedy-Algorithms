#include <iostream>
#include <queue>
using namespace std;

// Define a job struct to hold the details of a job
struct Job {
    int id;
    int priority;
    int duration;
};

// Define a comparison operator for the priority queue
struct CompareJob {
    bool operator()(const Job& j1, const Job& j2) {
        return j1.priority < j2.priority;
    }
};

int main() {
    // Create a priority queue of jobs
    priority_queue<Job, vector<Job>, CompareJob> jobQueue;

    // Add some jobs to the queue
    jobQueue.push({1, 2, 5});
    jobQueue.push({2, 1, 3});
    jobQueue.push({3, 3, 2});
    jobQueue.push({4, 2, 4});

    // Process the jobs in order of priority
    while (!jobQueue.empty()) {
        Job currentJob = jobQueue.top();
        jobQueue.pop();

        // Process the current job
        cout << "Processing job " << currentJob.id << endl;
        for (int i = 0; i < currentJob.duration; i++) {
            // Simulate the job taking some time to complete
            cout << "  Processing... " << i+1 << "/" << currentJob.duration << endl;
        }
    }

    return 0;
}
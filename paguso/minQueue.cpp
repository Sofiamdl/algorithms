
#include <bits/stdc++.h>

using namespace std;

void enqueue(queue<uint32_t> *main_queue, deque<pair <uint32_t, int> > *min_queue, uint32_t value, uint32_t *push) { 
  main_queue->push(value);
  
  while ((min_queue->size() > 0) && ((*min_queue)[min_queue->size() - 1].first > value)) {
    min_queue->pop_back();
  }
  min_queue->push_back(make_pair(value, *push));
  (*push) = (*push) + 1;
}


void dequeue(queue<uint32_t> *main_queue, deque<pair <uint32_t, int> > *min_queue, uint32_t *pop) { 
  if (min_queue->front().first == main_queue->front()){
    min_queue->pop_front();
  };
  main_queue->pop();
  (*pop) = (*pop) + 1;
}

uint32_t min(deque<pair <uint32_t, int> > *min_queue) {
  return min_queue->front().first;
}

uint32_t gerador(uint32_t Xk) {
  long long num = 1ULL << 32;
  return (1664525*Xk+1013904223) % num;
}

int main() {
  uint32_t S, B, N, P;

  queue<uint32_t> main_vector;
  deque<pair <uint32_t,int> > min_vector;

  uint32_t push = 0;
  uint32_t pop = 0;

  cin >> S >> B >> N >> P;


  // burn in (começa enfileirando da semente)
  for (int i = 0; i < B; i++) {
    enqueue(&main_vector, &min_vector, S, &push);
    S = gerador(S);
  } 

  for (int i = 0; i < N; i++) {
    if (S % 10 < P) {
      S = gerador(S);
      enqueue(&main_vector, &min_vector, S, &push);
    } else {
      dequeue(&main_vector, &min_vector, &pop);
    }
    S = gerador(S);
    cout << min_vector.size() << ' ' << min_vector.front().second - pop << '\n';
  } 

  return 0;
}


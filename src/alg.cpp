// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int cnt = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        cnt++
      }
    }
  }
  return cnt;
}

int countPairs2(int *arr, int len, int value) {
  int cnt = 0;
  int end = len - 1;
  while (end > 0) {
    if (arr[end] > value) {
      end--;
    }
    else {
      break;
    }
  }
  for (int i = 0; i < len; i++) {
    for (int j = end; j > i; j--) {
      if (arr[i] + arr[j] == value)
        cnt++;
      }
  }
  return cnt;
}

int binarySearch(int* arr, int low, int high, int value) {
  int first = -1, l = low, r = high;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    if (arr[mid] >= value) {
      r = mid - 1;
      if (arr[mid] == value) {
        first = mid;
      }
      } else {
        l = mid + 1;
      }
  }
  if (first == -1) {
    return 0;
  }
  int last = first;
  l = first;
  r = high;
  whle (l <= r) {
    int mid = l + (r - l) / 2;
    if (arr[mid] <= value) {
      l = mid + 1;
      if (arr[mid] == value) {
        last = mid;
      }
      } else {
        r = mid - 1;
      }
  }
  return last - first + 1;
}

int countPairs3(int *arr, int len, int value) {
  int cnt = 0;
  for (int i = 0; i < len; i++) {
    cnt += binarySearch(arr, i + 1, len - 1, value - arr[i]);
  }
  return cnt;
}

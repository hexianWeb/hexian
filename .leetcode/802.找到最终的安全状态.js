/*
 * @lc app=leetcode.cn id=802 lang=javascript
 *
 * [802] 找到最终的安全状态
 */

// @lc code=start
/**
 * @param {number[][]} graph
 * @return {number[]}
 */
var eventualSafeNodes = function (graph) {
  const n = graph.length;
  const visited = new Set();
  const ans = [];
  const dfs = (i) => {
    if (visited.has(i)) {
      return false;
    }
    visited.add(i);
    for (const neibor of graph[i]) {
      if (!dfs(neibor)) {
        return false;
      }
    }
    graph[i] = [];
    visited.delete(i);
    return true;
  };

  for (let index = 0; index < graph.length; index++) {
    if (dfs(index)) {
      ans.push(index);
    }
  }
  return ans;
};
// @lc code=end

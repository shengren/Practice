class Solution {
    string connect(vector<string> &segments) {
        string concatenation = "";
        for (int i = 0; i < segments.size(); ++i)
            concatenation += segments[i];
        return (concatenation == "") ? "/" : concatenation;
    }
public:
    string simplifyPath(string path) {
        vector<string> simple_path;
        for (int i = 0; i < path.size();) {
            string segment = "";
            segment += path[i++];
            while (i < path.size() && path[i] != '/')
                segment += path[i++];
            if (segment == "/..") {
                if (!simple_path.empty())
                    simple_path.pop_back();
            } else if (segment == "/.") {
                // do nothing
            } else if (segment.size() > 1) {
                simple_path.push_back(segment);
            }
        }
        return connect(simple_path);
    }
};

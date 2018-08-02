/**
 * Definition of Column:
 * class Column {
 * public:
 *     int key;
 *     String value;
 *     Column(int key, string value) {
 *         this->key = key;
 *         this->value = value;
 *    }
 * }
 */


class MiniCassandra {
public:
    MiniCassandra() {
        // do intialization if necessary
    }
    map<string,map<int,string>> cassandra_hash;
    /*
     * @param raw_key: a string
     * @param column_key: An integer
     * @param column_value: a string
     * @return: nothing
     */
    void insert(string &raw_key, int column_key, string &column_value) {
        // write your code here
         if(cassandra_hash.find(raw_key) == cassandra_hash.end())
            cassandra_hash[raw_key] = map<int,string>();
        cassandra_hash[raw_key][column_key] = column_value;
    }

    /*
     * @param raw_key: a string
     * @param column_start: An integer
     * @param column_end: An integer
     * @return: a list of Columns
     */
    vector<Column> query(string &raw_key, int column_start, int column_end) {
        // write your code here
        vector<Column> ret;
        if(cassandra_hash.find(raw_key) == cassandra_hash.end())
            return ret;
        map<int,string>::iterator iter1 = cassandra_hash[raw_key].lower_bound(column_start);
        for(iter1;iter1!=cassandra_hash[raw_key].end(); ++iter1)
        {
            if(iter1->first > column_end)
                break;
            ret.push_back(Column(iter1->first,iter1->second));
        }
        return ret;
    }
};

Conclusion: an easy implentation of mini-cassandra nosql database

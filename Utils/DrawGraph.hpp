#pragma once
#include <fstream>
#include <map>
#include <string>
#include <utility>

// https://blog.csdn.net/H_18763886211/article/details/112290232
class DrawGraph
{
public:
    DrawGraph(std::string file_path = "./Display/display.dot", int mode = 1)
        : file(std::move(file_path)), mode(mode)
    {
        out.open(file, std::ios::app);
    }
    ~DrawGraph() { out.close(); }
    static constexpr int DiGraph = 1, Graph = 0;
    void Start()
    {
        if(mode == DiGraph)
            out << "digraph my_graph{" << std::endl;
        else if(mode == Graph)
            out << "graph my_graph{" << std::endl;
    }

    void Set(const std::string &key, const std::string &val)
    {
        out << "  " << key << " = " << val << ';' << std::endl;
        out.close();
    }
    int CreateNode(
        const std::string &node_name, const std::map<std::string, std::string> &parameter)
    {
        out << "  " << node_name;
        int i          = 0;
        bool needBrace = true;
        for(const auto& p : parameter) {
            i++;
            if(needBrace) {
                out << "[";
                needBrace = false;
            }
            out << p.first << "=" << p.second;
            if(i < parameter.size()) out << ",";
        }
        if(!needBrace) {
            out << "]";
        }

        out << ';' << std::endl;

        out.close();
        str2int[node_name]  = ++node_count;
        int2str[node_count] = node_name;

        return node_count;
    }

    int CreateRelationship(
        const std::string &start_name, const std::string &end_name, const std::string &label = "")
    {

        out << "  " << start_name;

        if(mode == DiGraph) {
            out << " -> ";
        }
        else if(mode == Graph) {
            out << " -- ";
        }
        out << end_name;

        if(label != std::string("")) {
            out << "[label=" << label << "]";
        }
        out << ';' << std::endl;

        out.close();
        return ++relation_count;
    }

    int CreateRelationship(
        const std::string &start_name,
        const std::string &end_name,
        const std::map<std::string, std::string> &parameter)
    {
        out << "  " << start_name;
        if(mode == DiGraph) {
            out << " -> ";
        }
        else if(mode == Graph) {
            out << " -- ";
        }
        out << end_name;

        int i          = 0;
        bool needBrace = true;
        for(const auto& p : parameter) {
            i++;
            if(needBrace) {
                out << "[";
                needBrace = false;
            }
            out << p.first << "=" << p.second;
            if(i < parameter.size()) out << ",";
        }
        if(!needBrace) {
            out << "]";
        }
        out << ';' << std::endl;

        out.close();
        return ++relation_count;
    }

    void AppendProperty(const std::string &detail)
    {
        out << detail << std::endl;
        out.close();
    }

    void DeleteProperty(const std::string &detail)
    {
        out << detail << std::endl;
        out.close();
    }
    void End()
    {
        out << "}" << std::endl;
        out.close();
    }

private:
    std::map<std::string, int> str2int;
    std::map<int, std::string> int2str;
    std::string file = "./temp.dot";
    std::ofstream out;
    int node_count = 0, relation_count = 0;
    int mode;
};

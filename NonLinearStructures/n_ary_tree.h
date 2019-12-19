#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct NAryTreeNode
{
    std::string Name;
    bool IsDir;
    std::vector<NAryTreeNode*> Children;
};

struct FileSystem
{
    using Node = NAryTreeNode;
    using NodePtr = NAryTreeNode*;

private:
    NodePtr root;
    NodePtr cwd;  // 当前工作目录
public:
    FileSystem()
    {
        root = new Node{"/", true, {}};
        cwd = root;  // 当前目录为root
    }

    NodePtr find(const std::string& path)
    {
        if (path.empty()) {
            return nullptr;
        }
        if (path[0] == '/') {
            return find_impl(root, path.substr(1));
        } else {
            return find_impl(cwd, path);
        }
    }

    bool add(const std::string& path, bool is_dir)
    {
        if (path[0] == '/') {
            return add_impl(root, path.substr(1), is_dir);
        } else {
            return add_impl(cwd, path, is_dir);
        }
    }
    bool change_dir(const std::string& path)
    {
        auto found = find(path);
        if (found && found->IsDir) {
            cwd = found;
            std::cout << "current dir change to " << path << std::endl;
            return true;
        }
        std::cout << path << " not found" << std::endl;
        return false;
    }
    void show_path(const std::string& path)
    {
        auto found = find(path);
        if (not found) {
            std::cout << "No such path: " << path << "." << std::endl;
            return;
        }

        if (found->IsDir) {
            for (auto child : found->Children) {
                std::cout << (child->IsDir ? "d " : "- ") << child->Name << std::endl;
            }
        } else {
            std::cout << "- " << found->Name << std::endl;
        }
    }
private:
    NodePtr find_impl(NodePtr directory, const std::string& path)
    {
        if (path.empty()) {
            return directory;
        }
        auto sep = path.find('/');
        // "dir0/dir1/dir2" 
        std::string current_path = (sep == std::string::npos ? path : path.substr(0, sep));  // dir0
        std::string rest_path = (sep == std::string::npos ? "" : path.substr(sep + 1));      // dir1/dir2
        auto found = std::find_if(directory->Children.begin(), directory->Children.end(),
            [&](const NodePtr child) {
            return child->Name == current_path;
        });

        if (found != directory->Children.end()) {
            return find_impl(*found, rest_path);
        }

        return nullptr;
    }
    bool add_impl(NodePtr directory, const std::string& path, bool is_dir)
    {
        //if (!is_dir) {
        //    std::cout << "is not a directory" << std::endl;
        //    return false;
        //}

        // "dir0/dir1/dir2"
        auto sep = path.find('/');
         
        if (sep == std::string::npos) {
            // dir2
            auto found = std::find_if(directory->Children.begin(), directory->Children.end(),
                [&](const NodePtr child) {
                return child->Name == path;
            });
            if (found != directory->Children.end()) {
                std::cout << path << " is exist" << std::endl;
                return false;
            }
            directory->Children.push_back(new Node{path, is_dir, {}});
            return true;
        } else {
            std::string next_dir = path.substr(0, sep);  // dir0
            auto found = std::find_if(directory->Children.begin(), directory->Children.end(),
                [&](const NodePtr child) {
                return child->Name == path;
            });
            if (found != directory->Children.end()) {
                // dir0 不存在
                return add_impl(*found, path.substr(sep + 1), is_dir);
            }
            
            std::cout << path << " is error" << std::endl;
            return false;
        }
    }
};


void test_nary_tree()
{
    FileSystem fs;
    fs.add("usr", true);       // Add directory usr in "/"
    fs.add("etc", true);       // Add directory etc in "/"
    fs.add("var", true);       // Add directory var in "/"
    fs.add("tmp_file", false); // Add file tmp_file in "/"

    std::cout << "Files/Directories under \"/\"" << std::endl;
    fs.show_path("/"); // List files/directories in "/"

    std::cout << std::endl;
    fs.change_dir("usr");
    fs.add("Packt", true);
    fs.add("Packt/Downloads", true);
    fs.add("Packt/Downloads/newFile.cpp", false);

    std::cout << "Let’s see the contents of dir usr: " << std::endl;
    fs.show_path("usr"); // This will not print the path successfully, since we’re already inside the dir usr. And there’s no directory named usr inside it.

    std::cout << "Let’s see the contents of \"/usr\"" << std::endl;
    fs.show_path("/usr");

    std::cout << "Let’s see the contents of \"/usr/Packt/Downloads\"" << std::endl;
    fs.show_path("/usr/Packt/Downloads");
}
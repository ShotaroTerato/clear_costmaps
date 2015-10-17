#include "ros/ros.h"
#include <cstdlib>
#include "std_srvs/Empty.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "clear_costmap_client");
    ros::NodeHandle n;
    ros::ServiceClient client = n.serviceClient<std_srvs::Empty>("/move_base/clear_costmaps");

    ros::Rate r(10);

    while(n.ok())
    {
        std_srvs::Empty srv;

        if(client.call(srv))
        {
            ROS_INFO("clear!");
        }
        else
        {
            ROS_ERROR("Faild to call service clear_costmaps");
        }
        r.sleep();
    }
    return 0;
}

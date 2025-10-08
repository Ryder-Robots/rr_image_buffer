#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "sensor_msgs/msg/camera_info.hpp"

namespace rr_image_buffer {

/**
 * @class RrImageBuffer
 * @brief image camera buffering service.
 * 
 * When images are streamed, provides buffering service. 
 */
class RrImageBuffer : public rclcpp::Node
{
public:
    RrImageBuffer() : Node("camera_buffer") {
        init();
    }

    /**
     * @fn init()
     * @brief perform node inilization.
     */
    void init();
private:
    /**
     * @fn image_callback
     * @brief called when new image is recieved.
     */
    void image_callback(const sensor_msgs::msg::Image::SharedPtr msg);

    /**
     * @fn info_callback
     * @brief called when new camera info is recieved
     */
    void info_callback(const sensor_msgs::msg::CameraInfo::SharedPtr msg);
};
}
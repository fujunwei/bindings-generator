    ~$(current_class.target_class_name)();
    std::shared_ptr<three::$(current_class.target_class_name)> getImpl() {
    	return m_impl;
    }

    void setImpl(std::shared_ptr<three::$(current_class.target_class_name)> impl) {
    	m_impl = impl;
    }

    void setImpl(three::$(current_class.target_class_name)& impl);

private:
    std::shared_ptr<three::$(current_class.target_class_name)> m_impl;
};

} // namespace blink

#endif
